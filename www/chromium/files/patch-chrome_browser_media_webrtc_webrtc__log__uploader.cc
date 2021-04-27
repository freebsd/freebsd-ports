--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -360,6 +360,8 @@ void WebRtcLogUploader::SetupMultipart(
   const char product[] = "Chrome_Android";
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
