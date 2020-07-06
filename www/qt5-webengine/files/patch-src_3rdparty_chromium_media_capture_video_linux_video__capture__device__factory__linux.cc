--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2020-04-08 09:41:36 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc
@@ -315,6 +315,7 @@ void VideoCaptureDeviceFactoryLinux::GetSupportedForma
     supported_format.pixel_format =
         VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
             v4l2_format.pixelformat);
+    supported_format.pixel_format = PIXEL_FORMAT_UNKNOWN;
 
     if (supported_format.pixel_format == PIXEL_FORMAT_UNKNOWN)
       continue;
