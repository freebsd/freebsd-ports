--- ext/cdparanoia/gstcdparanoia.c.orig	Fri Jun  3 06:59:43 2005
+++ ext/cdparanoia/gstcdparanoia.c	Fri Jun  3 07:00:13 2005
@@ -561,6 +561,7 @@
     gint16 *cdda_buf;
     gint64 timestamp;
     GstFormat format;
+    GstEvent *discont_ev;
 
     /* convert the sequence sector number to a timestamp */
     format = GST_FORMAT_TIME;
@@ -574,7 +575,6 @@
       gst_pad_convert (src->srcpad, sector_format,
           get_relative (src, src->cur_track, src->cur_sector), &format,
           &timestamp);
-      GstEvent *discont_ev;
 
       if (src->flush_pending) {
         src->flush_pending = FALSE;
