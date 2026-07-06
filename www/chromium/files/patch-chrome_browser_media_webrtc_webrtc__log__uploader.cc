--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -97,7 +97,7 @@ std::string GetLogUploadProduct(WebRtcLogUploadSite si
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
