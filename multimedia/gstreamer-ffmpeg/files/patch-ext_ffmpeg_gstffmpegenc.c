--- ext/ffmpeg/gstffmpegenc.c.orig	Mon Oct 11 13:11:57 2004
+++ ext/ffmpeg/gstffmpegenc.c	Mon Oct 11 13:12:39 2004
@@ -406,6 +406,7 @@
   if (ret_size < 0) {
     g_warning ("ffenc_%s: failed to encode buffer", oclass->in_plugin->name);
     gst_buffer_unref (inbuf);
+    gst_buffer_unref (outbuf);
     return;
   }
 
