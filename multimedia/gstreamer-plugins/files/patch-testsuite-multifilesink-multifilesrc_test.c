--- testsuite/multifilesink/multifilesrc_test.c.orig	Tue Oct 12 18:02:55 2004
+++ testsuite/multifilesink/multifilesrc_test.c	Tue Oct 12 18:24:43 2004
@@ -3,14 +3,14 @@
 int
 main (int argc, char **argv)
 {
-  gst_init (&argc, &argv);
-
   GSList *locations;
   int i;
 
   //gboolean retval;
 
   GstElement *pipeline, *src, *sink;
+
+  gst_init (&argc, &argv);
 
   g_print ("creating sink\n");
   sink = gst_element_factory_make ("multifilesink", "sink");
