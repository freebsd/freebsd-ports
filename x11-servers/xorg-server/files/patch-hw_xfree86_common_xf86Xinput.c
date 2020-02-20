* Recognize devd backend as a source of auto-configured devices
*
--- hw/xfree86/common/xf86Xinput.c.orig	2017-03-15 18:05:25 UTC
+++ hw/xfree86/common/xf86Xinput.c
@@ -871,7 +871,7 @@ xf86NewInputDevice(InputInfoPtr pInfo, D
 {
     InputDriverPtr drv = NULL;
     DeviceIntPtr dev = NULL;
-    Bool paused;
+    Bool paused = 0;
     int rval;
     char *path = NULL;
 
@@ -1034,6 +1034,7 @@ NewInputDeviceRequest(InputOption *optio
         if (strcmp(key, "_source") == 0 &&
             (strcmp(value, "server/hal") == 0 ||
              strcmp(value, "server/udev") == 0 ||
+             strcmp(value, "server/devd") == 0 ||
              strcmp(value, "server/wscons") == 0)) {
             is_auto = 1;
             if (!xf86Info.autoAddDevices) {
