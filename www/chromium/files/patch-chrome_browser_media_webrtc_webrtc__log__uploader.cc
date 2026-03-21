--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -95,7 +95,7 @@ std::string GetLogUploadProduct() {
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
