--- lib/pqueue.c.orig	2018-02-20 04:24:55.000000000 +0700
+++ lib/pqueue.c	2022-01-15 00:17:05.525677000 +0700
@@ -172,7 +172,10 @@ pqueue_dequeue (struct pqueue *queue)
 void
 pqueue_remove_at (int index, struct pqueue *queue)
 {
-  queue->array[index] = queue->array[--queue->size];
+  if (index == --queue->size)
+    return; /* we're removing the last entry */
+
+  queue->array[index] = queue->array[queue->size];
 
   if (index > 0
       && (*queue->cmp) (queue->array[index],
