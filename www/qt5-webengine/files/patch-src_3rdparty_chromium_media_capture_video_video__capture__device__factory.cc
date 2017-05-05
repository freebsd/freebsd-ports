--- src/3rdparty/chromium/media/capture/video/video_capture_device_factory.cc.orig	2017-04-23 20:12:45 UTC
+++ src/3rdparty/chromium/media/capture/video/video_capture_device_factory.cc
@@ -55,7 +55,7 @@ void VideoCaptureDeviceFactory::Enumerat
 }
 
 #if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_ANDROID) && \
-    !defined(OS_WIN)
+    !defined(OS_WIN) && !defined(OS_BSD)
 // static
 VideoCaptureDeviceFactory*
 VideoCaptureDeviceFactory::CreateVideoCaptureDeviceFactory(
