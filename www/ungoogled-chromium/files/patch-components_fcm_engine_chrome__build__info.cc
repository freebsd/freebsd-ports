--- components/fcm/engine/chrome_build_info.cc.orig	2026-11-17 11:49:09 UTC
+++ components/fcm/engine/chrome_build_info.cc
@@ -27,7 +27,7 @@ ChromePlatform GetPlatform() {
   return ChromePlatform::kAndroid;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ChromePlatform::kCros;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ChromePlatform::kLinux;
 #else
   // For all other platforms, return as LINUX.
