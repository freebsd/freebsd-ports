--- ./talk/third_party/mediastreamer/msqueue.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msqueue.c	Fri Apr 21 10:56:34 2006
@@ -53,4 +53,7 @@
    q->size++;
 }
 
+MSMessage *ms_queue_peek_last(MSQueue *q){
+	return q->last;
+}
 
