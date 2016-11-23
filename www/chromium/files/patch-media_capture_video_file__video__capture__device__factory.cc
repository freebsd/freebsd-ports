--- media/capture/video/file_video_capture_device_factory.cc.orig	2016-10-06 04:02:21.000000000 +0300
+++ media/capture/video/file_video_capture_device_factory.cc	2016-10-13 07:41:41.678945000 +0300
@@ -49,7 +49,7 @@
 #elif defined(OS_MACOSX)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::MACOSX_AVFOUNDATION
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE
 #else
