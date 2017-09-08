--- src/pthread_debug.cc.orig	2017-07-03 08:59:29 UTC
+++ src/pthread_debug.cc
@@ -76,6 +76,7 @@ void print_pthread_attr(const char *call
 }
 
 
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr)
 {
   (void) caller;
@@ -120,6 +121,7 @@ void print_pthread_condattr(const char *
   (void) c_attr;
 #endif
 }
+#endif
 
 
 int PTHREAD_Debug = 0;
