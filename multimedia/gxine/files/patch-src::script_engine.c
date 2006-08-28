--- src/script_engine.c.orig	Thu Jun 15 17:13:25 2006
+++ src/script_engine.c	Tue Jul 11 00:38:49 2006
@@ -1554,7 +1554,7 @@
 
   pthread_mutexattr_t attr;
   pthread_mutexattr_init (&attr);
-  pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE_NP);
+  pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE);
   pthread_mutex_init (&se->lock, &attr);
   pthread_mutexattr_destroy (&attr);
 
