--- src/pthread_debug.cc.orig	2018-05-09 08:49:58 UTC
+++ src/pthread_debug.cc
@@ -87,6 +87,7 @@ print_pthread_attr(const char *caller, p
   fprintf(stderr, "%-18s :  %-14s = %ld\n", caller, "stacksize", (long) stacksize);
 }
 
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void
 print_pthread_mutexattr(const char *caller, pthread_mutexattr_t *m_attr)
 {
@@ -118,6 +119,7 @@ PTHREAD_PRIO_NONE);
   }
 #endif
 }
+#endif
 
 void
 print_pthread_condattr(const char *caller, pthread_condattr_t *c_attr)
