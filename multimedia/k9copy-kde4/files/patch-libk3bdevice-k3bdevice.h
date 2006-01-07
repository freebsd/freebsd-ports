--- libk3bdevice/k3bdevice.h.orig      Mon Dec 12 10:32:59 2005
+++ libk3bdevice/k3bdevice.h   Wed Dec 14 23:49:42 2005
@@ -28,6 +28,7 @@

 #ifdef Q_OS_FREEBSD
 struct cam_device;
+#define stat64 stat
 #endif

 namespace K3bDevice
