--- src/chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -98,7 +98,7 @@ std::string GetLogUploadProduct(WebRtcLo
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
