--- fifo.h.orig	Fri Aug  6 09:09:02 1999
+++ fifo.h	Wed Aug 18 22:28:00 2004
@@ -4,7 +4,8 @@
 #ifndef __FIFO_H__
 #define __FIFO_H__
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stddef.h>
 #ifndef NULL
 #define NULL (void *) 0
@@ -19,8 +20,8 @@
 	const T *data;
 	struct queue *next;
     } queue;
-    struct queue *start;
-    struct queue **end;
+    struct fifo<T>::queue *start;
+    struct fifo<T>::queue **end;
     int length;
 
 public:
@@ -61,7 +62,7 @@
 template<class T>
 void fifo<T>::clear(void)
 {
-    struct queue *ptr, *next;
+    struct fifo<T>::queue *ptr, *next;
     
     ptr=start;
     while (ptr!=NULL)
@@ -79,7 +80,7 @@
 template<class T>
 fifo<T>::~fifo(void)
 {
-    struct queue *ptr, *next;
+    struct fifo<T>::queue *ptr, *next;
     
     ptr=start;
     while (ptr!=NULL)
@@ -94,12 +95,12 @@
 template<class T>
 void fifo<T>::enqueue(const T *d)
 {
-    struct queue *q;
+    struct fifo<T>::queue *q;
     
 #ifdef DEBUG_FIFO
     cerr<<"Queue "<<(void *) d<<"\n";
 #endif
-    q=new(struct queue);
+    q=new(struct fifo<T>::queue);
     q->next=NULL;
     q->data=d;
     *end=q;
@@ -110,7 +111,7 @@
 template<class T>
 void fifo<T>::insert(const T *d)
 {
-    struct queue *q;
+    struct fifo<T>::queue *q;
 #ifdef CONSIST_CHECK
     if (end==NULL)
     {
@@ -119,7 +120,7 @@
     }
 #endif
     
-    q=new(struct queue);
+    q=new(struct fifo<T>::queue);
     q->next=start;
     q->data=d;
     start=q;
@@ -132,7 +133,7 @@
 const T *fifo<T>::dequeue(void)
 {
     const T *d;
-    struct queue *q;
+    struct fifo<T>::queue *q;
 #ifdef CONSIST_CHECK
     if (end==NULL)
     {
@@ -206,7 +207,7 @@
 template<class T>
 void fifo<T>::rev(void)
 {
-    struct queue *p, *n, *hdr, **ep;
+    struct fifo<T>::queue *p, *n, *hdr, **ep;
 #ifdef CONSIST_CHECK
     if (end==NULL || d->end==NULL)
     {
