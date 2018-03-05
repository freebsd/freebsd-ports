--- src/names/thread_resolve.c.orig	2017-03-18 16:11:42 UTC
+++ src/names/thread_resolve.c
@@ -162,6 +162,10 @@ thread_pool_routine(void *dt)
 
       pthread_mutex_unlock(&resolvemtx);
    }
+
+   /* close mutex */
+   close_mutex();
+
    return NULL;
 }
 
@@ -280,9 +284,6 @@ thread_close(void)
 {
   /* thread pool shutdown */ 
   stop_threads();
-   
-  /* close mutex */ 
-  close_mutex();
 }
 
 const char *
