--- extensions/common/features/feature.cc.orig	2019-03-11 22:00:58 UTC
+++ extensions/common/features/feature.cc
@@ -26,6 +26,8 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return MACOSX_PLATFORM;
 #elif defined(OS_WIN)
   return WIN_PLATFORM;
+#elif defined(OS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
