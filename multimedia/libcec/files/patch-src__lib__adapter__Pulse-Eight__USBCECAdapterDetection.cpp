--- ./src/lib/adapter/Pulse-Eight/USBCECAdapterDetection.cpp.orig	2012-10-17 11:35:39.000000000 +0200
+++ ./src/lib/adapter/Pulse-Eight/USBCECAdapterDetection.cpp	2012-10-17 11:35:52.000000000 +0200
@@ -427,8 +427,6 @@
   for (i = 0; i < 8; ++i)
   {
     (void)snprintf(devicePath, sizeof(devicePath), "/dev/ttyU%d", i);
-    if (strDevicePath && strcmp(devicePath, strDevicePath) != 0)
-      continue;
     if (!access(devicePath, 0))
     {
       snprintf(deviceList[iFound].path, sizeof(deviceList[iFound].path), "%s", devicePath);
