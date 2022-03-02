--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -363,6 +363,10 @@ void WebRtcLogUploader::SetupMultipart(
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
