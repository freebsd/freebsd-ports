--- components/metrics/dwa/dwa_service.cc.orig	2025-12-05 10:12:50 UTC
+++ components/metrics/dwa/dwa_service.cc
@@ -244,7 +244,7 @@ void DwaService::RecordCoarseSystemInformation(
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_WINDOWS);
 #elif BUILDFLAG(IS_MAC)
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_MACOS);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_LINUX);
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(b/366276323): Populate set_platform using more granular
