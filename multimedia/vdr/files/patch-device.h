--- device.h.orig
+++ device.h
@@ -25,7 +25,7 @@
 #include "thread.h"
 #include "tools.h"
 
-#define MAXDEVICES         16 // the maximum number of devices in the system
+#define MAXDEVICES         64 // the maximum number of devices in the system
 #define MAXPIDHANDLES      64 // the maximum number of different PIDs per device
 #define MAXRECEIVERS       16 // the maximum number of receivers per device
 #define MAXVOLUME         255
@@ -105,7 +105,7 @@ class cDevice : public cThread {
   friend class cDeviceHook;
 private:
   static int numDevices;
-  static int useDevice;
+  static uint64_t useDevice;
   static cDevice *device[MAXDEVICES];
   static cDevice *primaryDevice;
   static cDevice *avoidDevice;
