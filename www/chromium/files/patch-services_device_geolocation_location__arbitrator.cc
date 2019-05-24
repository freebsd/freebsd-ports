--- services/device/geolocation/location_arbitrator.cc.orig	2019-04-30 22:22:56 UTC
+++ services/device/geolocation/location_arbitrator.cc
@@ -157,7 +157,7 @@ LocationArbitrator::NewNetworkLocationProvider(
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
