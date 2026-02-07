--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -159,7 +159,7 @@ LocationArbitrator::NewSystemLocationProvider() {
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
