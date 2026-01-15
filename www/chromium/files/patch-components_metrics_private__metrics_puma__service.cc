--- components/metrics/private_metrics/puma_service.cc.orig	2026-01-14 08:33:23 UTC
+++ components/metrics/private_metrics/puma_service.cc
@@ -71,7 +71,7 @@ Platform GetCurrentPlatform() {
   return Platform::PLATFORM_WINDOWS;
 #elif BUILDFLAG(IS_MAC)
   return Platform::PLATFORM_MACOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return Platform::PLATFORM_LINUX;
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(b/463580425): Differentiate between Android platforms.
