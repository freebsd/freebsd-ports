--- extensions/common/features/feature.cc.orig	2025-08-07 06:57:29 UTC
+++ extensions/common/features/feature.cc
@@ -32,6 +32,8 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return FUCHSIA_PLATFORM;
 #elif BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
   return DESKTOP_ANDROID_PLATFORM;
+#elif BUILDFLAG(IS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
