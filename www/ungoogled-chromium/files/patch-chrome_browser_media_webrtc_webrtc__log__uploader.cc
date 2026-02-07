--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -101,7 +101,7 @@ std::string GetLogUploadProduct() {
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
