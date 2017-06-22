--- device/geolocation/location_arbitrator.cc.orig	2017-06-05 19:03:07 UTC
+++ device/geolocation/location_arbitrator.cc
@@ -182,7 +182,7 @@ LocationArbitrator::NewNetworkLocationProvider(
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
