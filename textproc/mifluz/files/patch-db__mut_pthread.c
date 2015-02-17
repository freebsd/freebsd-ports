--- db/mut_pthread.c.orig
+++ db/mut_pthread.c
@@ -50,6 +50,10 @@
 #define	pthread_self		thr_self
 #endif
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 /*
  * __db_pthread_mutex_init --
  *	Initialize a MUTEX.
