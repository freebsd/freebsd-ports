--- src/pthread_debug.c.orig	2010-11-12 20:22:44.000000000 +0800
+++ src/pthread_debug.c	2011-02-26 03:30:00.000000000 +0800
@@ -77,6 +77,7 @@
 }
 
 
+#if defined (PTHREAD_MUTEXATTR_CONDATTR)
 void print_pthread_mutexattr(const char *caller,  pthread_mutexattr_t *m_attr)
 {
   /*
@@ -116,6 +117,7 @@
   }
 #endif
 }
+#endif
 
 
 int PTHREAD_Debug = 0;
