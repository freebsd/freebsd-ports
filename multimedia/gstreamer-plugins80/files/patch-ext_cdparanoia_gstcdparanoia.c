--- ext/cdparanoia/gstcdparanoia.c.orig	Mon Jul 11 14:36:25 2005
+++ ext/cdparanoia/gstcdparanoia.c	Mon Jul 11 14:38:41 2005
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
@@ -788,9 +788,15 @@
 
   /* fail if the device couldn't be found */
   if (src->d == NULL) {
+#if defined(__FreeBSD__)
     GST_ELEMENT_ERROR (src, RESOURCE, OPEN_READ,
         (_("Could not open CD device %s for reading."),
-            src->d->cdda_device_name), ("cdda_identify failed"));
+	     src->d->dev->device_path), ("cdda_identify failed"));
+#else
+    GST_ELEMENT_ERROR (src, RESOURCE, OPEN_READ,
+        (_("Could not open CD device %s for reading."),
+	     src->d->cdda_device_name), ("cdda_identify failed"));
+#endif
     return FALSE;
   }
 
@@ -805,9 +811,15 @@
 
   /* open the disc */
   if (cdda_open (src->d)) {
+#if defined(__FreeBSD__)
+    GST_ELEMENT_ERROR (src, RESOURCE, OPEN_READ,
+        (_("Could not open CD device %s for reading."),
+            src->d->dev->device_path), ("cdda_open failed"));
+#else
     GST_ELEMENT_ERROR (src, RESOURCE, OPEN_READ,
         (_("Could not open CD device %s for reading."),
             src->d->cdda_device_name), ("cdda_open failed"));
+#endif
     cdda_close (src->d);
     src->d = NULL;
     return FALSE;
