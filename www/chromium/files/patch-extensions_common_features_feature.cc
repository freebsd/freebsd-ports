--- extensions/common/features/feature.cc.orig	2026-09-25 15:26:43 UTC
+++ extensions/common/features/feature.cc
@@ -32,6 +32,8 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return WIN_PLATFORM;
 #elif BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
   return DESKTOP_ANDROID_PLATFORM;
+#elif BUILDFLAG(IS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
