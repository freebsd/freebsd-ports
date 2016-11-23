--- content/browser/device_sensors/data_fetcher_shared_memory.h.orig	2016-10-06 04:02:18.000000000 +0300
+++ content/browser/device_sensors/data_fetcher_shared_memory.h	2016-10-14 15:15:34.071484000 +0300
@@ -45,7 +45,7 @@
   bool Start(ConsumerType consumer_type, void* buffer) override;
   bool Stop(ConsumerType consumer_type) override;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 #if !defined(OS_CHROMEOS)
   DeviceMotionHardwareBuffer* motion_buffer_ = nullptr;
   DeviceOrientationHardwareBuffer* orientation_buffer_ = nullptr;
