--- media/video/capture/file_video_capture_device_factory.cc.orig	2015-06-19 21:29:29 UTC
+++ media/video/capture/file_video_capture_device_factory.cc
@@ -51,7 +51,7 @@
       command_line_file_path.value(),
       kFileVideoCaptureDeviceName,
       VideoCaptureDevice::Name::AVFOUNDATION));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   device_names->push_back(VideoCaptureDevice::Name(
       command_line_file_path.value(),
       kFileVideoCaptureDeviceName,
