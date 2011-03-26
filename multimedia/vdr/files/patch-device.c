--- device.c.orig
+++ device.c
@@ -65,7 +65,7 @@ bool cDeviceHook::DeviceProvidesTranspon
 #define MIN_PRE_1_3_19_PRIVATESTREAM 10
 
 int cDevice::numDevices = 0;
-int cDevice::useDevice = 0;
+uint64_t cDevice::useDevice = 0;
 int cDevice::nextCardIndex = 0;
 int cDevice::currentChannel = 1;
 cDevice *cDevice::device[MAXDEVICES] = { NULL };
