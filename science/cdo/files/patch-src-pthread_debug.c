--- src/pthread_debug.c.orig	Mon Dec  4 16:11:40 2006
+++ src/pthread_debug.c	Sat Apr  7 01:12:05 2007
@@ -77,6 +77,7 @@
 }
 
 
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr)
 {
   int protocol, kind, pshared;
@@ -107,6 +108,7 @@
   POUT2(caller, pshared, PTHREAD_PROCESS_SHARED, PTHREAD_PROCESS_PRIVATE);
 #endif
 }
+#endif
 
 
 int PTHREAD_Debug = 0;
