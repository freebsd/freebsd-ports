--- src/pthread_debug.c.orig	2007-05-14 14:30:15.000000000 +0800
+++ src/pthread_debug.c	2007-10-25 16:30:35.000000000 +0800
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
