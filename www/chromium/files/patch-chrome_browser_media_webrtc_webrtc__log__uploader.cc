--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -98,7 +98,7 @@ std::string GetLogUploadProduct(WebRtcLogUploadSite si
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
