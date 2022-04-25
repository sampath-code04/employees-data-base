#include <stdio.h>
#include<stdlib.h>
typedef struct customers
{
    char name[20];
    int acc;
    float bal;
}cus;
void balance(cus*);
void increment(cus*);
void main() 
{
    cus c[5];
    char ch;
    for(int i=0;i<5;i++)
    {
        printf("\nEnter customer %d name:",i+1);
        scanf("%s",c[i].name);
        printf("\nEnter customer %d account naumber:",i+1);
        scanf("%d",&c[i].acc);
        printf("\nEnter customer %d balance:",i+1);
        scanf("%f",&c[i].bal);
        
    }
    system("clear");
    printf("\n******************Customers Details:*********************");
    for(int i=0;i<5;i++)
    {
       printf("\n\nCustomer %d:",i+1);
       printf("\nName:%s",c[i].name);
       printf("\nAccount Number:%d",c[i].acc);
       printf("\nBalance:%.2f",c[i].bal);
    }
    balance(c);
    increment(c);
}
void balance(cus *c)
{
    printf("\n\nDisplaying Custosmers name[Balance<200]:");
    for(int i=0;i<5;i++)
    {
        if(c[i].bal<200)
            printf("\n\n%s",c[i].name);
    }
    
}

void increment(cus *c)
 {
    char ch;
    float N;
    Check:
    printf("\n\nWould you like to increment for Eligible Custosmer[Balance>1000](y/n):");
    scanf("%s",&ch);
    if(ch == 'y')
        goto Amount;
    else
        goto Ex;
    Amount:
    if(ch == 'y')
    {
        printf("\nHow much could you like to increment(minimum Rs.100):");
        scanf("%f",&N);
        if(N<100){
            printf("\nSorry!,minimum amount is Rs. 100 .\nYou can add only more than Rs. 100");
            printf("\nRedirecting...........");
            goto Check;
        }
        else{
            for(int j=0;j<5;j++){
                if(c[j].bal>1000)
                    c[j].bal+=N;
            }
             printf("\n******************Incremented*****************"); 
        }
    }
    printf("\n\nCustomers list[Balance>1000]:");
    for(int j=0;j<5;j++){
        if(c[j].bal>1000){
            printf("\nCustomer Name:%s \nBalance:%.2f\n",c[j].name,c[j].bal);
        }
    }
    Ex:
    printf("\nExit.");
   
}
