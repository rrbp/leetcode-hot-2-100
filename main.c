#include <stdio.h>
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode *node =(struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=val;
    node->next=NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head= createNode(0);
    struct ListNode *tail=head;
    struct ListNode *h1=l1;
    struct ListNode *h2=l2;
    int carry=0;
    while(h1!=NULL || h2!= NULL ||carry!=0)
    {
        int sum=carry;
        if(h1!=NULL)
        {
            sum+=h1->val;
            h1=h1->next;
        }
        if(h2!=NULL)
        {
            sum+=h2->val;
            h2=h2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        tail->next= createNode(sum%10);
        tail=tail->next;

    }
    return head->next;
}

int main() {
    // 创建第一个链表 2 -> 4 -> 3 (表示342)
    struct ListNode *l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // 创建第二个链表 5 -> 6 -> 4 (表示465)
    struct ListNode *l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    // 计算两个链表的和
    struct ListNode *result = addTwoNumbers(l1, l2);

    // 打印结果链表
    while (result != NULL) {
        printf("%d", result->val);
        result = result->next;
    }

    return 0;
}