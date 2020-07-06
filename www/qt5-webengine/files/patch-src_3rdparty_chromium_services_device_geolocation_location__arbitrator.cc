--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -159,7 +159,7 @@ LocationArbitrator::NewNetworkLocationProvider(
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
