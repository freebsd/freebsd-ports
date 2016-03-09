--- src/thread_resolve.c.orig	2015-06-06 07:18:29 UTC
+++ src/thread_resolve.c
@@ -161,6 +161,10 @@ thread_pool_routine(void *dt)
 
       pthread_mutex_unlock(&resolvemtx);
    }
+
+   /* close mutex */
+   close_mutex();
+
    return NULL;
 }
 
@@ -279,9 +283,6 @@ thread_close(void)
 {
   /* thread pool shutdown */ 
   stop_threads();
-   
-  /* close mutex */ 
-  close_mutex();
 }
 
 const char *
