--- extensions/common/features/feature.cc.orig	2025-09-10 13:22:16 UTC
+++ extensions/common/features/feature.cc
@@ -30,6 +30,8 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return WIN_PLATFORM;
 #elif BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
   return DESKTOP_ANDROID_PLATFORM;
+#elif BUILDFLAG(IS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
