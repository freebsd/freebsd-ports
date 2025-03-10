--- services/device/geolocation/location_provider_manager.cc.orig	2025-02-20 09:59:21 UTC
+++ services/device/geolocation/location_provider_manager.cc
@@ -91,7 +91,7 @@ LocationProviderManager::LocationProviderManager(
 #if BUILDFLAG(IS_ANDROID)
   // On Android, default to using the platform location provider.
   provider_manager_mode_ = kPlatformOnly;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ash / Lacros / Linux, default to using the network location provider.
   provider_manager_mode_ = kNetworkOnly;
 #else
