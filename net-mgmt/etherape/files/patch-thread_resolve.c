--- src/thread_resolve.c.orig	Tue Apr 25 09:08:28 2006
+++ src/thread_resolve.c	Mon May 29 00:37:45 2006
@@ -167,6 +167,10 @@
 
       pthread_mutex_unlock(&resolvemtx);
    }
+
+   /* close mutex */
+   close_mutex();
+
    return NULL;
 }
 
@@ -268,9 +272,6 @@
 {
   /* thread pool shutdown */ 
   stop_threads();
-   
-  /* close mutex */ 
-  close_mutex();
 }
 
 /* returns 1 if the current dns implementation has a socket wich needs a select() */
