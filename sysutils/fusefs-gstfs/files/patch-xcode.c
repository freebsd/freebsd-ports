--- xcode.c.orig	2014-03-04 20:53:11.000000000 +0100
+++ xcode.c	2014-03-04 20:54:14.000000000 +0100
@@ -41,7 +41,6 @@
 
     struct pipe_params thread_params;
     pthread_t thread;
-    void *thread_status;
 
     pipeline = gst_parse_launch(pipeline_str, &error);
     if (error)
@@ -83,7 +82,7 @@
 
     // close read-side so pipe will terminate
     close(pipefds[1]);
-    pthread_join(thread, thread_status);
+    pthread_join(thread, NULL);
 
     return 0;
 }
