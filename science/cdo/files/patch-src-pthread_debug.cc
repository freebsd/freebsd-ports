--- src/pthread_debug.cc.orig	2017-11-21 10:41:21 UTC
+++ src/pthread_debug.cc
@@ -80,6 +80,7 @@ void print_pthread_attr(const char *call
 }
 
 
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr)
 {
   (void) caller;
@@ -109,6 +110,7 @@ void print_pthread_mutexattr(const char 
   }
 #endif
 }
+#endif
 
 
 void print_pthread_condattr(const char *caller, pthread_condattr_t *c_attr)
