--- src/callbacks.c.orig	2012-03-29 16:03:49 UTC
+++ src/callbacks.c
@@ -979,7 +979,7 @@ cb_presentation(Widget w _GL_UNUSED, XtPointer client_
 cb_presentation(Widget w _GL_UNUSED, XtPointer client_data _GL_UNUSED, XtPointer call_data _GL_UNUSED)
 {
     int pid;
-    sighandler_t sigold;
+    sig_t sigold;
 
     BEGINMESSAGE(cb_presentation)
 
