--- src/3rdparty/chromium/media/capture/video/file_video_capture_device_factory.cc.orig	2017-04-23 10:37:42 UTC
+++ src/3rdparty/chromium/media/capture/video/file_video_capture_device_factory.cc
@@ -50,7 +50,7 @@ void FileVideoCaptureDeviceFactory::GetD
   device_names->push_back(VideoCaptureDevice::Name(
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureDevice::Name::AVFOUNDATION));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   device_names->push_back(VideoCaptureDevice::Name(
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureDevice::Name::V4L2_SINGLE_PLANE));
