--- hw/xfree86/common/xf86Xinput.c.orig	2016-07-19 17:07:29 UTC
+++ hw/xfree86/common/xf86Xinput.c
@@ -841,7 +841,7 @@ xf86NewInputDevice(InputInfoPtr pInfo, D
 {
     InputDriverPtr drv = NULL;
     DeviceIntPtr dev = NULL;
-    Bool paused;
+    Bool paused = 0;
     int rval;
     char *path = NULL;
 
@@ -996,6 +996,7 @@ NewInputDeviceRequest(InputOption *optio
         if (strcmp(key, "_source") == 0 &&
             (strcmp(value, "server/hal") == 0 ||
              strcmp(value, "server/udev") == 0 ||
+             strcmp(value, "server/devd") == 0 ||
              strcmp(value, "server/wscons") == 0)) {
             is_auto = 1;
             if (!xf86Info.autoAddDevices) {
