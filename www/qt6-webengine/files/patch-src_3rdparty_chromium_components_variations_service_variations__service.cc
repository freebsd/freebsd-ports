--- src/3rdparty/chromium/components/variations/service/variations_service.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/variations/service/variations_service.cc
@@ -102,7 +102,7 @@ std::string GetPlatformString() {
   return "android";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "fuchsia";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_SOLARIS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_BSD)
   // Default BSD and SOLARIS to Linux to not break those builds, although these
   // platforms are not officially supported by Chrome.
   return "linux";
