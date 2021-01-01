--- media/capture/video/video_capture_device_client.cc.orig	2019-12-16 21:50:49 UTC
+++ media/capture/video/video_capture_device_client.cc
@@ -297,7 +297,7 @@ void VideoCaptureDeviceClient::OnIncomingCapturedData(
 // see http://linuxtv.org/downloads/v4l-dvb-apis/packed-rgb.html.
 // Windows RGB24 defines blue at lowest byte,
 // see https://msdn.microsoft.com/en-us/library/windows/desktop/dd407253
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       fourcc_format = libyuv::FOURCC_RAW;
 #elif defined(OS_WIN)
       fourcc_format = libyuv::FOURCC_24BG;
