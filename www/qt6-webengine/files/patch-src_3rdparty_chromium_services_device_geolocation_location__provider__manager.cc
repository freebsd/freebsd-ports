--- src/3rdparty/chromium/services/device/geolocation/location_provider_manager.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/services/device/geolocation/location_provider_manager.cc
@@ -86,7 +86,7 @@ LocationProviderManager::LocationProviderManager(
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   // On Android and iOS, default to using the platform location provider.
   provider_manager_mode_ = LPMM::kPlatformOnly;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ash / Lacros / Linux, default to using the network location provider.
   provider_manager_mode_ = LPMM::kNetworkOnly;
 #else
