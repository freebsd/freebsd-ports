--- configure.ac.orig	2015-08-08 16:29:47.571735000 +0200
+++ configure.ac	2015-08-08 16:33:23.011860000 +0200
@@ -231,11 +231,10 @@
 		[
 		have_gst_check=no
 		])
-
-	AM_CONDITIONAL(HAVE_GST_CHECK, test "$have_gst_check" = yes)
-
 ])
 
+AM_CONDITIONAL(HAVE_GST_CHECK, test "$have_gst_check" = yes)
+
 AS_IF([test "$with_gstreamer010" != no], [
   
 	PKG_CHECK_MODULES(GST010, [
