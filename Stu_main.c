// ������ϵͳ
// ʵ�ֵĹ���



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct fraction
{
    int chinese;
    int math;
    int english;
}Stu_Fraction;



typedef struct Student
{
    char name[20];
    char ID[20];
    char sex[10];
    int age;
    int class;
    int grade;
    Stu_Fraction Frac;
    int S_count;
    struct Student *next;
}StudentNode,*Student;


// ��ʾ�˵�
void printMenu(){

    printf("--------------------ѧ������ϵͳ--------------------\n");
    printf("-----------------------1.¼��-----------------------\n");
    printf("-----------------------2.ɾ��-----------------------\n");
    printf("-----------------------3.����-----------------------\n");
    printf("-----------------------4.�޸�-----------------------\n");
    printf("-----------------------5.����-----------------------\n");
    printf("-----------------------6.��ʾ-----------------------\n");
    printf("-----------------------7.����-----------------------\n");
    printf("-----------------------8.�˳�-----------------------\n");
    printf("----------------------------------------------------\n");

}





// ¼����Ϣ
int add_data(Student S){

    int Stu_count = 0;
    printf("¼����Ϣ����:\n");
    scanf("%d", &Stu_count);
    
    // ����һ��ָ��ʼ��ָ��ѧ����������һ���ڵ�
    StudentNode *head = (StudentNode *)malloc(sizeof(StudentNode));
    head = S;
    while(head->next!=NULL)
        head = head->next;

    while(Stu_count>0){
        // ����һ��ѧ���ڵ�
        Student One = (StudentNode *)malloc(sizeof(StudentNode));

        // ���뵥��ѧ����Ϣ
        printf("�����뵱ǰѧ��������:\n");
        scanf("%s",One->name);
        printf("�����뵱ǰѧ����ѧ��:\n");
        scanf("%s",One->ID);
        printf("�����뵱ǰѧ�����Ա�:\n");
        scanf("%s",One->sex);
        printf("�����뵱ǰѧ��������:\n");
        scanf("%d",&One->age);
        printf("�����뵱ǰѧ�����꼶:\n");
        scanf("%d",&One->grade);
        printf("�����뵱ǰѧ���İ༶:\n");
        scanf("%d",&One->class);
        printf("�����뵱ǰѧ���ĳɼ�(���� ��ѧ Ӣ��(�Կո����)):\n");
        scanf("%d %d %d",&One->Frac.chinese,&One->Frac.math,&One->Frac.english);

        // ����ѧ������Ϣ���뵽������
        head->next = One;
        head = One;
        Stu_count--;
    }
    head->next = NULL;

    if(Stu_count==0){
        S->S_count+=1;
        printf("¼��ɹ�!\n");
    }else{
        printf("¼��ʧ��!");
    }

}


// ��ʾ��Ϣ
void printStu(Student S){
    // ����һ���ڵ����ڱ�������
    StudentNode *head = (StudentNode *)malloc(sizeof(StudentNode));
    head = S->next;
    printf(" %-5s       %3s      %3s   %3s   %s   %3s   %5s %5s %5s\n","NAME","ID","SEX","AGE","GRADE","CLASS","CHINESE","MATH","ENGLISH");
    while (head!=NULL)
    {
        
        printf("%-5s   %-5s  %3s   %3d    %3d     %3d   %5d    %5d %4d\n",head->name,head->ID,head->sex,head->age,head->grade,head->class,head->Frac.chinese,head->Frac.math,head->Frac.english);
        head = head->next;
    }
    
    
    
}

// ����IDɾ��ѧ����Ϣ

bool delete(Student S,char ID[]){
    // ����һ��ָ����в��Ҳ�������һ��ָ��ʼ��ָ����ҽ�����һ��λ��
    StudentNode * before = (StudentNode *)malloc(sizeof(StudentNode));
    before = S;
    StudentNode * search = (StudentNode *)malloc(sizeof(StudentNode));
    search = before->next;
    
    while (search!=NULL)
    {
        if(!strcmp(ID,search->ID)){
            // ɾ��ѧ����Ϣ
            // ��������һ��
            if(search->next==NULL){
                before->next = NULL;
                free(search);
            }else{
                // �������һ��
                before->next = search->next;
                free(search);
            }
            S->S_count--;
            break;
        }else{
            before = search;
            search = search->next;
        }
    }
    return true;
}

// ����ID������Ϣ
bool search(Student S,char ID[]){

    // ����һ��ָ����б���ѧ������
    StudentNode *s = (StudentNode *)malloc(sizeof(StudentNode));
    if(S==NULL){
        return false;
    }
    s = S->next;
    while(s!=NULL){
        if(!strcmp(ID,s->ID)){
            // ������������ʾ��Ϣ
            printf(" %-5s       %3s      %3s   %3s   %s   %3s   %5s %5s %5s\n","NAME","ID","SEX","AGE","GRADE","CLASS","CHINESE","MATH","ENGLISH");
            printf("%-5s   %-5s  %3s   %3d    %3d     %3d   %5d    %5d %4d\n", s->name, s->ID, s->sex, s->age, s->grade, s->class, s->Frac.chinese, s->Frac.math, s->Frac.english);
            break;
        }
        s = s->next;
    }

    return true;
}

// ����ID�޸�ѧ����Ϣ


// ���ݳɼ���������

// ��ʾϵͳ�е�ѧ������
int count(Student S){
    return S->S_count;
}
//�˳�
void Exit(){
    exit(0);
}

int main(int argc ,char *argv[]){

    

    


    // ����һ��ѧ������
        Student S= (Student)malloc(sizeof(StudentNode));
        S->next = NULL;         //��ͷ���
        S->S_count = 0;         //��ǰ����Ϊ0

        while (1)
        {
            printMenu();
            printf("������������룺");
            int choose;
            scanf("%d", &choose);
            switch (choose)
            {
            case 1:
                // ¼��ѧ����Ϣ
                add_data(S);
                break;
            case 2:
                // ����ѧ��ɾ��ѧ����Ϣ
                char DEL_ID[20];
                printf("��������Ҫɾ��ѧ����ѧ�ţ�");
                scanf("%s", DEL_ID);
                delete (S, DEL_ID);
                break;

            case 3:
                // ����ѧ�Ų���ѧ����Ϣ
                char S_ID[20];
                printf("��������Ҫ����ѧ����ѧ�ţ�");
                scanf("%s", &S_ID);
                search(S, S_ID);
                break;

            case 6:
                // ��ʾѧ������Ϣ
                printStu(S);
                break;
            case 7:
                // ��ʾ��ǰϵͳ�е�����
                int s = count(S);
                printf("��ǰϵͳ�е�����Ϊ:%d\n",s);
                break;

            case 8:
                // �˳�ϵͳ
                Exit();

            default:
                printMenu();
                break;
            }
        }
    

    // // ����һ��ѧ������
    // Student S= (Student)malloc(sizeof(StudentNode));
    // S->next = NULL;         //��ͷ���

    // add_data(S);
    // printStu(S);
    // delete (S, "1704241014");
    // printStu(S);
    // if(search(S, "1704241014"))
    //     printf("YES!\n");
    // else
    //     printf("No!\n");
    // search(S, "1704241014");


    // return 0;
}