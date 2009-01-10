--- src/cheese-webcam.c.orig	2008-09-09 11:59:18.000000000 -0400
+++ src/cheese-webcam.c	2008-09-09 12:01:14.000000000 -0400
@@ -301,7 +301,9 @@ cheese_webcam_get_video_devices_from_hal
   {
     char                   *device;
     char                   *gstreamer_src, *product_name;
+#ifdef VIDIOC_QUERYCAP
     struct v4l2_capability  v2cap;
+#endif
     struct video_capability v1cap;
 
     device = libhal_device_get_property_string (hal_ctx, udis[i], "video4linux.device", &error);
@@ -327,7 +329,11 @@ cheese_webcam_get_video_devices_from_hal
       libhal_free_string (device);
       continue;
     }
+#ifdef VIDIOC_QUERYCAP
     ok = ioctl (fd, VIDIOC_QUERYCAP, &v2cap);
+#else
+    ok = -1;
+#endif
     if (ok < 0)
     {
       ok = ioctl (fd, VIDIOCGCAP, &v1cap);
@@ -346,6 +352,7 @@ cheese_webcam_get_video_devices_from_hal
     }
     else
     {
+#ifdef VIDIOC_QUERYCAP
       guint cap = v2cap.capabilities;
       g_print ("Detected v4l2 device: %s\n", v2cap.card);
       g_print ("Driver: %s, version: %d\n", v2cap.driver, v2cap.version);
@@ -361,6 +368,7 @@ cheese_webcam_get_video_devices_from_hal
       }
       gstreamer_src = "v4l2src";
       product_name  = (char *) v2cap.card;
+#endif
     }
 
     priv->webcam_devices[priv->num_webcam_devices].hal_udi           = g_strdup (udis[i]);
