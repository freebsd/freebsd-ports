--- media/capture/video/file_video_capture_device_factory.cc.orig	2015-10-14 11:10:41.842256000 -0400
+++ media/capture/video/file_video_capture_device_factory.cc	2015-10-14 11:11:13.400581000 -0400
@@ -49,7 +49,7 @@
   device_names->push_back(VideoCaptureDevice::Name(
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureDevice::Name::AVFOUNDATION));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   device_names->push_back(VideoCaptureDevice::Name(
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureDevice::Name::V4L2_SINGLE_PLANE));
