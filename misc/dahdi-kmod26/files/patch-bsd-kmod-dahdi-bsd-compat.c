--- bsd-kmod/dahdi/bsd-compat.c.orig	2016-03-11 07:22:10.097436000 +0000
+++ bsd-kmod/dahdi/bsd-compat.c	2016-03-11 07:22:32.048183000 +0000
@@ -48,6 +48,10 @@
 #include <sys/refcount.h>
 #include <sys/sbuf.h>
 
+#if __FreeBSD_version >= 1100101
+#define taskqueue_enqueue_fast(queue, task)    taskqueue_enqueue(queue, task)
+#endif
+
 /*
  * Tasklet API
  */
