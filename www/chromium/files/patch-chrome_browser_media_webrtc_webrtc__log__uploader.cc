--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -106,7 +106,7 @@ std::string GetLogUploadProduct() {
   const char product[] = "Chrome_Mac";
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
