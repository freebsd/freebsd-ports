--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -167,7 +167,7 @@ LocationArbitrator::NewNetworkLocationProvider(
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
