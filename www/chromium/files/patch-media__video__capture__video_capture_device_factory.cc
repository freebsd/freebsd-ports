--- media/video/capture/video_capture_device_factory.cc.orig	2015-04-24 22:45:15.000000000 +0200
+++ media/video/capture/video_capture_device_factory.cc	2015-04-24 22:45:36.000000000 +0200
@@ -50,7 +50,7 @@
   callback.Run(device_names.Pass());
 }
 
-#if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FREEBSD)
 // static
 VideoCaptureDeviceFactory*
 VideoCaptureDeviceFactory::CreateVideoCaptureDeviceFactory(
