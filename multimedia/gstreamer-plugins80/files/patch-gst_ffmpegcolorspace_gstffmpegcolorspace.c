--- gst/ffmpegcolorspace/gstffmpegcolorspace.c.orig	Wed Apr 28 15:10:45 2004
+++ gst/ffmpegcolorspace/gstffmpegcolorspace.c	Wed Apr 28 15:11:00 2004
@@ -306,7 +306,7 @@
   g_return_if_fail (GST_IS_FFMPEGCOLORSPACE (space));
 
   if (space->from_pixfmt == PIX_FMT_NB || space->to_pixfmt == PIX_FMT_NB) {
-    GST_ELEMENT_ERROR (space, CORE, NOT_IMPLEMENTED, NULL,
+    GST_ELEMENT_ERROR (space, CORE, NOT_IMPLEMENTED, (NULL),
         ("attempting to convert colorspaces between unknown formats"));
     gst_buffer_unref (inbuf);
     return;
