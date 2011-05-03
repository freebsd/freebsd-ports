--- src/callbacks.c.orig	2011-05-03 02:52:57.000000000 -0400
+++ src/callbacks.c	2011-05-03 02:55:24.000000000 -0400
@@ -1031,7 +1031,7 @@
     XtPointer client_data, call_data;
 {
     int pid;
-    sighandler_t sigold;
+    sig_t sigold;
 
     BEGINMESSAGE(cb_presentation)
 
