Workaround for an incompatibility bug in our libudev-devd.
See https://github.com/FreeBSDDesktop/libudev-devd/issues/19

--- gst-libs/gst/vaapi/gstvaapidisplay_drm.c.orig	2025-12-25 14:44:26 UTC
+++ gst-libs/gst/vaapi/gstvaapidisplay_drm.c
@@ -118,6 +118,7 @@ get_default_device_path (GstVaapiDisplay * display)
     udev_list_entry_foreach (l, udev_enumerate_get_list_entry (e)) {
       syspath = udev_list_entry_get_name (l);
       device = udev_device_new_from_syspath (udev, syspath);
+#ifdef __linux__
       parent = udev_device_get_parent (device);
 
       for (i = 0; allowed_subsystems[i] != NULL; i++)
@@ -129,7 +130,7 @@ get_default_device_path (GstVaapiDisplay * display)
         udev_device_unref (device);
         continue;
       }
-
+#endif
       devpath = udev_device_get_devnode (device);
       fd = open (devpath, O_RDWR | O_CLOEXEC);
       if (fd < 0) {
