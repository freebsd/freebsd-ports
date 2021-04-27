--- services/device/geolocation/location_arbitrator.cc.orig	2021-04-14 18:41:08 UTC
+++ services/device/geolocation/location_arbitrator.cc
@@ -162,7 +162,7 @@ LocationArbitrator::NewNetworkLocationProvider(
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
