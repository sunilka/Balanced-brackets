#include<stdio.h>
#include<string.h>
#include<malloc.h>
//int size=0;
char stack[100000];
int top=-1;
int *ans;
int k=0;

void push(char ele)
{
    stack[++top]=ele;
}

void pop()
{
    stack[top]='*';
    top=top-1;
}

void cal()
{
    int l=0;
    char s[10000];
    int n,i,j;
    scanf("%s",s);
    n=strlen(s);

    for(i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='{'  || s[i]=='[')
            push(s[i]);

        else if(s[i]==')' && stack[top]=='(' )
            pop();

        else if(s[i]=='}' && stack[top]=='{')
            pop();

        else if(s[i]==']' && stack[top]=='[')
            pop();

        else
        {
            l=1;
            break;
            //top=-1;
        }
    }

    if(l==1 || i==n && top!=-1)
    {
        ans[k]=0;
       // printf("%d ",ans[k]);
        k++;
        //printf("NO");
    }

    /*else if(i==n && top!=-1)
    {
        ans[k]=0;
        k++;
    }*/

    else
    {
        ans[k]=1;
        //printf("%d ",ans[k]);
        k++;
     // printf("YES");

    }
    top=-1;
}

void printans()
{
    int i=0;
    for(i=0;i<k;i++)
    {
        if(ans[i]==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
    int j;
    int nooftestcases;
    scanf("%d",&nooftestcases);
    //size=nooftestcases;

    ans=(int *)malloc(nooftestcases*sizeof(int));



    while(nooftestcases--)
    {
        cal();
    }

    printans();


}
