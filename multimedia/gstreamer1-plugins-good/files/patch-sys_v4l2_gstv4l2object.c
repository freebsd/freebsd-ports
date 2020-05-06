--- sys/v4l2/gstv4l2object.c.orig	2020-04-06 14:45:19 UTC
+++ sys/v4l2/gstv4l2object.c
@@ -2891,8 +2891,9 @@ gst_v4l2_object_is_dmabuf_supported (GstV4l2Object * v
   }
 
   /* Expected to fail, but ENOTTY tells us that it is not implemented. */
+  /* FreeBSD cuse sends EINVAL? */
   v4l2object->ioctl (v4l2object->video_fd, VIDIOC_EXPBUF, &expbuf);
-  if (errno == ENOTTY)
+  if (errno == ENOTTY || errno == EINVAL)
     ret = FALSE;
 
   return ret;
