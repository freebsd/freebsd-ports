--- src/3rdparty/chromium/components/variations/service/variations_service.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/variations/service/variations_service.cc
@@ -100,7 +100,7 @@ std::string GetPlatformString() {
   return "android";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "fuchsia";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_SOLARIS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_BSD)
   // Default BSD and SOLARIS to Linux to not break those builds, although these
   // platforms are not officially supported by Chrome.
   return "linux";
