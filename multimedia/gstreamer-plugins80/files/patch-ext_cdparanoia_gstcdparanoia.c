--- ext/cdparanoia/gstcdparanoia.c.orig	Tue Jul  5 13:24:21 2005
+++ ext/cdparanoia/gstcdparanoia.c	Tue Jul  5 13:24:27 2005
@@ -562,6 +562,7 @@
     gint16 *cdda_buf;
     gint64 timestamp;
     GstFormat format;
+    GstEvent *discont_ev;
 
     /* convert the sequence sector number to a timestamp */
     format = GST_FORMAT_TIME;
@@ -575,7 +576,6 @@
       gst_pad_convert (src->srcpad, sector_format,
           get_relative (src, src->cur_track, src->cur_sector), &format,
           &timestamp);
-      GstEvent *discont_ev;
 
       if (src->flush_pending) {
         src->flush_pending = FALSE;
@@ -790,7 +790,11 @@
   if (src->d == NULL) {
     GST_ELEMENT_ERROR (src, RESOURCE, OPEN_READ,
         (_("Could not open CD device %s for reading."),
-            src->d->cdda_device_name), ("cdda_identify failed"));
+#if defined(__FreeBSD__)
+	     src->d->dev->device_path), ("cdda_identify failed"));
+#else
+	     src->d->cdda_device_name), ("cdda_identify failed"));
+#endif
     return FALSE;
   }
 
@@ -807,7 +811,11 @@
   if (cdda_open (src->d)) {
     GST_ELEMENT_ERROR (src, RESOURCE, OPEN_READ,
         (_("Could not open CD device %s for reading."),
+#if defined(__FreeBSD__)
+            src->d->dev->device_path), ("cdda_open failed"));
+#else
             src->d->cdda_device_name), ("cdda_open failed"));
+#endif
     cdda_close (src->d);
     src->d = NULL;
     return FALSE;
