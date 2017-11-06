--- media/capture/video/video_capture_device_client.cc.orig	2017-04-19 19:06:35 UTC
+++ media/capture/video/video_capture_device_client.cc
@@ -238,7 +238,7 @@ void VideoCaptureDeviceClient::OnIncomin
 // see http://linuxtv.org/downloads/v4l-dvb-apis/packed-rgb.html.
 // Windows RGB24 defines blue at lowest byte,
 // see https://msdn.microsoft.com/en-us/library/windows/desktop/dd407253
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       origin_colorspace = libyuv::FOURCC_RAW;
 #elif defined(OS_WIN)
       origin_colorspace = libyuv::FOURCC_24BG;
