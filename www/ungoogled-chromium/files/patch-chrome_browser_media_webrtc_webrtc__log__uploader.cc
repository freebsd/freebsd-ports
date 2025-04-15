--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2025-04-15 08:30:07 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -105,7 +105,7 @@ std::string GetLogUploadProduct() {
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
