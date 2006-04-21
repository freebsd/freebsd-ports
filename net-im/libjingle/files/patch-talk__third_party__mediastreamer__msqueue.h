--- ./talk/third_party/mediastreamer/msqueue.h.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msqueue.h	Fri Apr 21 10:56:34 2006
@@ -41,6 +41,8 @@
 
 void ms_queue_put(MSQueue *q, MSMessage *m);
 
+MSMessage *ms_queue_peek_last(MSQueue *q);
+
 #define ms_queue_can_get(q) ( (q)->size!=0 )
 
 #define ms_queue_destroy(q) g_free(q)
