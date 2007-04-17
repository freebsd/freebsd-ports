--- os/linux/linux.c.orig	Tue Apr 17 18:12:00 2007
+++ os/linux/linux.c	Tue Apr 17 18:13:10 2007
@@ -122,7 +122,11 @@
 #ifdef USE_MULTITHREADING
 	pthread_mutexattr_init(&attr);
 #ifndef OSX
+#ifndef PTHREAD_MUTEX_RECURSIVE_NP
+	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
+#else
 	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
+#endif
 #endif /* !OSX */
 #endif /* USE_MULTITHREADING */
 	return psOpenMalloc(MAX_MEMORY_USAGE);
