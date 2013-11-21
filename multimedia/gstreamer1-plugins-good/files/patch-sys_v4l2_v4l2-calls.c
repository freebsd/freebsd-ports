--- sys/v4l2/v4l2_calls.c.orig	2013-09-24 15:05:22.000000000 +0200
+++ sys/v4l2/v4l2_calls.c	2013-11-21 00:31:40.000000000 +0100
@@ -205,7 +205,11 @@
     standard.index = n;
 
     if (v4l2_ioctl (v4l2object->video_fd, VIDIOC_ENUMSTD, &standard) < 0) {
+#if defined(ENODATA)
       if (errno == EINVAL || errno == ENOTTY || errno == ENODATA)
+#else
+      if (errno == EINVAL || errno == ENOTTY)
+#endif
         break;                  /* end of enumeration */
       else {
         GST_ELEMENT_ERROR (e, RESOURCE, SETTINGS,
