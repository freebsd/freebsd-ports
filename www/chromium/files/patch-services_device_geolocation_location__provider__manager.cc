--- services/device/geolocation/location_provider_manager.cc.orig	2026-09-25 15:26:43 UTC
+++ services/device/geolocation/location_provider_manager.cc
@@ -392,7 +392,7 @@ LocationProviderManager::NewSystemLocationProvider() {
   return device::NewSystemLocationProvider(
       geolocation_system_permission_manager_->GetSystemGeolocationSource());
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS))
   return device::NewSystemLocationProvider();
 #else
   return nullptr;
