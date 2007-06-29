--- src/pthread_debug.c.orig	Mon May 14 14:30:15 2007
+++ src/pthread_debug.c	Fri Jun 29 00:24:12 2007
@@ -77,6 +77,7 @@
 }
 
 
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr)
 {
 #if defined (_POSIX_THREAD_PRIO_PROTECT) && defined (_POSIX_THREAD_PRIO_INHERIT)
@@ -115,6 +116,7 @@
   }
 #endif
 }
+#endif
 
 
 int PTHREAD_Debug = 0;
