--- src/pthread_debug.c.orig	Mon Dec  4 16:11:40 2006
+++ src/pthread_debug.c	Mon Dec 18 10:01:00 2006
@@ -77,6 +77,7 @@
 }
 
 
+#if __FreeBSD_version >= 600000
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr)
 {
   int protocol, kind, pshared;
@@ -107,6 +108,7 @@
   POUT2(caller, pshared, PTHREAD_PROCESS_SHARED, PTHREAD_PROCESS_PRIVATE);
 #endif
 }
+#endif
 
 
 int PTHREAD_Debug = 0;
