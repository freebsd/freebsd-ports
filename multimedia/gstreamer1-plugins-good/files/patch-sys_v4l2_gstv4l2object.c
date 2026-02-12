--- sys/v4l2/gstv4l2object.c.orig	2026-01-27 17:02:33 UTC
+++ sys/v4l2/gstv4l2object.c
@@ -573,7 +573,7 @@ v4l2_mmap_wrapper (gpointer start, gsize length, gint 
 
 #endif /* SIZEOF_OFF_T < 8 */
 
-#if defined(__linux__) && !defined(__GLIBC__)
+#if !defined(__GLIBC__)
 /* v4l2_ioctl always takes request as unsigned long int, not ioctl_req_t */
 static gint
 v4l2_ioctl_wrapper (gint fd, ioctl_req_t request, ...)
@@ -5385,7 +5385,9 @@ gst_v4l2_object_probe_caps (GstV4l2Object * v4l2object
     if (v4l2object->ioctl (v4l2object->video_fd, VIDIOC_CROPCAP, &cropcap) < 0) {
 
       switch (errno) {
+#ifdef ENODATA
         case ENODATA:
+#endif
         case ENOTTY:
           GST_INFO_OBJECT (v4l2object->dbg_obj,
               "Driver does not support VIDIOC_CROPCAP (%s), assuming pixel aspect ratio 1/1",
