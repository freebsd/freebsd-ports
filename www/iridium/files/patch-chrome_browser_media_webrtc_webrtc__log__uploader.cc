--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2022-10-05 07:34:01 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -362,6 +362,10 @@ void WebRtcLogUploader::SetupMultipart(
   const char product[] = "Chrome_ChromeOS";
 #elif BUILDFLAG(IS_FUCHSIA)
   const char product[] = "Chrome_Fuchsia";
+#elif defined(OS_OPENBSD)
+  const char product[] = "Chrome_OpenBSD";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
