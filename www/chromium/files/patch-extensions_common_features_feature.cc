--- extensions/common/features/feature.cc.orig	2021-04-14 18:41:04 UTC
+++ extensions/common/features/feature.cc
@@ -26,7 +26,7 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return LACROS_PLATFORM;
 #elif BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   return CHROMEOS_PLATFORM;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return LINUX_PLATFORM;
 #elif defined(OS_MAC)
   return MACOSX_PLATFORM;
