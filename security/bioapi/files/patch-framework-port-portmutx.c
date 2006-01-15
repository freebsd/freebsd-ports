--- framework/port/portmutx.c	Wed Jun  8 02:51:05 2005
+++ framework/port/portmutx.c	Thu Jan 12 11:45:43 2006
@@ -122,6 +122,7 @@
      * WIN32 mutexes are recursive, so match that behavior.
      */
 
+#if 0
     if ((status = pthread_mutexattr_settype(&attr, 
 #if defined (LINUX) 
         PTHREAD_MUTEX_RECURSIVE_NP)))
@@ -132,6 +133,7 @@
         (void) pthread_mutexattr_destroy(&attr);
         goto cleanup;
     }
+#endif
 
     if ((status = pthread_mutex_init(*mhandle, &attr)))
     {
