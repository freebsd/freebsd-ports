--- ext/theora/theoradec.c.orig	Wed Aug  4 16:29:13 2004
+++ ext/theora/theoradec.c	Wed Aug  4 16:30:47 2004
@@ -385,6 +385,7 @@
   gboolean res = TRUE;
   GstTheoraDec *dec;
   GstFormat format;
+  GstEvent *real_seek;
 
   dec = GST_THEORA_DEC (gst_pad_get_parent (pad));
 
@@ -405,7 +406,7 @@
         goto error;
 
       /* then seek with time on the peer */
-      GstEvent *real_seek = gst_event_new_seek (
+      real_seek = gst_event_new_seek (
           (GST_EVENT_SEEK_TYPE (event) & ~GST_SEEK_FORMAT_MASK) |
           format, value);
 
