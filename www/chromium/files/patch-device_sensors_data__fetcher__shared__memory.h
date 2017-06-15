--- device/sensors/data_fetcher_shared_memory.h.orig	2017-04-19 19:06:34 UTC
+++ device/sensors/data_fetcher_shared_memory.h
@@ -44,7 +44,7 @@ class DEVICE_SENSOR_EXPORT DataFetcherSh
   bool Start(ConsumerType consumer_type, void* buffer) override;
   bool Stop(ConsumerType consumer_type) override;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 #if !defined(OS_CHROMEOS)
   DeviceMotionHardwareBuffer* motion_buffer_ = nullptr;
   DeviceOrientationHardwareBuffer* orientation_buffer_ = nullptr;
