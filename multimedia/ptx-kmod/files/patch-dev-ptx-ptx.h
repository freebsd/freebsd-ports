--- dev/ptx/ptx.h.orig	2011-07-18 06:50:50.000000000 +0900
+++ dev/ptx/ptx.h	2011-07-18 06:51:26.000000000 +0900
@@ -218,7 +218,11 @@
 	struct cdev *dev[MAX_STREAM];
 	struct ptx_stream stream[MAX_STREAM];
 
+#if (__FreeBSD_version < 800000)
+	struct proc *ptxdaemon;
+#else
 	struct thread *ptxdaemon;
+#endif
 	int ring_pos;
 	int data_pos;
 
