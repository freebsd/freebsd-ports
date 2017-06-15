--- src/evdev.c.orig	2017-01-03 01:26:00 UTC
+++ src/evdev.c
@@ -38,9 +38,13 @@
 #include <X11/keysym.h>
 #include <X11/extensions/XI.h>
 
+#ifdef __linux__
 #include <linux/version.h>
+#endif
 #include <sys/stat.h>
+#ifdef HAVE_LIBUDEV
 #include <libudev.h>
+#endif
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -226,6 +230,7 @@ EvdevIsDuplicate(InputInfoPtr pInfo)
 static BOOL
 EvdevDeviceIsVirtual(const char* devicenode)
 {
+#ifdef HAVE_LIBUDEV
     struct udev *udev = NULL;
     struct udev_device *device = NULL;
     struct stat st;
@@ -256,6 +261,9 @@ out:
     udev_device_unref(device);
     udev_unref(udev);
     return rc;
+#else
+    return FALSE;
+#endif
 }
 
 
@@ -1062,11 +1070,13 @@ EvdevReadInput(InputInfoPtr pInfo)
     do {
         rc = libevdev_next_event(pEvdev->dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
         if (rc < 0) {
-            if (rc == -ENODEV) /* May happen after resume */
+            if (rc != -EAGAIN && rc != -EINTR && rc != -EWOULDBLOCK) {
+                /* May happen after resume or at device detach */
                 xf86RemoveEnabledDevice(pInfo);
-            else if (rc != -EAGAIN)
+                EvdevCloseDevice(pInfo);
                 LogMessageVerbSigSafe(X_ERROR, 0, "%s: Read error: %s\n", pInfo->name,
                                        strerror(-rc));
+            }
             break;
         } else if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
             if (pEvdev->mtdev)
@@ -1476,10 +1486,15 @@ EvdevAddAbsValuatorClass(DeviceIntPtr de
             continue;
 
         abs = libevdev_get_abs_info(pEvdev->dev, axis);
+#ifdef __linux__
 #if LINUX_VERSION_CODE > KERNEL_VERSION(2, 6, 30)
         /* Kernel provides units/mm, X wants units/m */
         resolution = abs->resolution * 1000;
 #endif
+#else
+        /* Kernel provides units/mm, X wants units/m */
+        resolution = abs->resolution * 1000;
+#endif
 
         xf86InitValuatorAxisStruct(device, axnum,
                                    atoms[axnum],
