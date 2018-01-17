--- src/3rdparty/chromium/content/browser/device_sensors/data_fetcher_shared_memory.h.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/device_sensors/data_fetcher_shared_memory.h
@@ -45,7 +45,7 @@ class CONTENT_EXPORT DataFetcherSharedMe
   bool Start(ConsumerType consumer_type, void* buffer) override;
   bool Stop(ConsumerType consumer_type) override;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 #if !defined(OS_CHROMEOS)
   DeviceMotionHardwareBuffer* motion_buffer_ = nullptr;
   DeviceOrientationHardwareBuffer* orientation_buffer_ = nullptr;
