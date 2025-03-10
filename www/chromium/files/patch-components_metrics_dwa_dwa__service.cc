--- components/metrics/dwa/dwa_service.cc.orig	2025-01-15 09:18:26 UTC
+++ components/metrics/dwa/dwa_service.cc
@@ -161,7 +161,7 @@ void DwaService::RecordCoarseSystemInformation(
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_WINDOWS);
 #elif BUILDFLAG(IS_MAC)
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_MACOS);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_LINUX);
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(b/366276323): Populate set_platform using more granular
