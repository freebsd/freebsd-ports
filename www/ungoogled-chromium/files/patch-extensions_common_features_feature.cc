--- extensions/common/features/feature.cc.orig	2025-01-25 09:34:31 UTC
+++ extensions/common/features/feature.cc
@@ -29,6 +29,8 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return WIN_PLATFORM;
 #elif BUILDFLAG(IS_FUCHSIA)
   return FUCHSIA_PLATFORM;
+#elif BUILDFLAG(IS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
