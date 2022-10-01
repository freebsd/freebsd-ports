--- extensions/common/features/feature.cc.orig	2022-10-01 07:40:07 UTC
+++ extensions/common/features/feature.cc
@@ -34,6 +34,8 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return WIN_PLATFORM;
 #elif BUILDFLAG(IS_FUCHSIA)
   return FUCHSIA_PLATFORM;
+#elif defined(OS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
