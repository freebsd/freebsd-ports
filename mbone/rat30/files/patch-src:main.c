--- src/main.c.orig	Fri Feb  3 00:23:21 2006
+++ src/main.c	Fri Feb  3 00:23:37 2006
@@ -118,11 +118,11 @@
 	NEW_QUEUE(pckt_queue_struct, rtcp_pckt_queue)
 	NEW_QUEUE(rx_queue_struct,   rx_unit_queue)
 
-#define INIT_QUEUE(T,Q) Q##_ptr[0] = &Q##[0]; \
+#define INIT_QUEUE(T,Q) Q##_ptr[0] = &Q[0]; \
 			Q##_ptr[0]->queue_empty_flag = 1; \
                         Q##_ptr[0]->head_ptr         = NULL; \
                         Q##_ptr[0]->tail_ptr         = NULL; \
-			Q##_ptr[1] = &Q##[1]; \
+			Q##_ptr[1] = &Q[1]; \
 			Q##_ptr[1]->queue_empty_flag = 1; \
                         Q##_ptr[1]->head_ptr         = NULL; \
                         Q##_ptr[1]->tail_ptr         = NULL;
