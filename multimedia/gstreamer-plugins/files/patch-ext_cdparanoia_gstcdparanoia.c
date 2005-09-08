--- ext/cdparanoia/gstcdparanoia.c.orig	Mon Aug 29 13:50:49 2005
+++ ext/cdparanoia/gstcdparanoia.c	Thu Sep  1 15:30:11 2005
@@ -562,6 +562,7 @@
     gint16 *cdda_buf;
     gint64 timestamp;
     GstFormat format;
+    GstEvent *discont_ev;
 
     /* convert the sequence sector number to a timestamp */
     format = GST_FORMAT_TIME;
@@ -572,7 +573,6 @@
 
     if (!src->discont_sent && (is_track_switch (src, src->cur_sector) ||
             (src->prev_sec != src->cur_sector))) {
-      GstEvent *discont_ev;
 
       if (src->cur_track == src->d->tracks) {
         GST_DEBUG_OBJECT (src, "End of CD");
@@ -815,9 +815,15 @@
 
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
