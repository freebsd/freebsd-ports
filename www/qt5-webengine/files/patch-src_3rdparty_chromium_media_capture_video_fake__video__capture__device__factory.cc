--- src/3rdparty/chromium/media/capture/video/fake_video_capture_device_factory.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/media/capture/video/fake_video_capture_device_factory.cc
@@ -200,7 +200,7 @@ void FakeVideoCaptureDeviceFactory::GetDeviceDescripto
   for (const auto& entry : devices_config_) {
     device_descriptors->emplace_back(
         base::StringPrintf("fake_device_%d", entry_index), entry.device_id,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE
 #elif defined(OS_MACOSX)
         VideoCaptureApi::MACOSX_AVFOUNDATION
