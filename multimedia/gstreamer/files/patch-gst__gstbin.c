--- gst/gstbin.c.orig	Tue Apr 18 21:12:49 2006
+++ gst/gstbin.c	Tue Apr 18 21:39:56 2006
@@ -2406,7 +2406,7 @@
 {
   gint ret;
 
-  if (G_TYPE_CHECK_INSTANCE_TYPE (element, GPOINTER_TO_INT (interface))) {
+  if (G_TYPE_CHECK_INSTANCE_TYPE (element, (GType)interface)) {
     ret = 0;
   } else {
     /* we did not find the element, need to release the ref
