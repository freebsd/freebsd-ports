--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2021-09-24 04:25:58 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -363,6 +363,8 @@ void WebRtcLogUploader::SetupMultipart(
   const char product[] = "Chrome_ChromeOS";
 #elif defined(OS_FUCHSIA)
   const char product[] = "Chrome_Fuchsia";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
