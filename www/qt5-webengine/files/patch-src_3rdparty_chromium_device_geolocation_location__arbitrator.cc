--- src/3rdparty/chromium/device/geolocation/location_arbitrator.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/geolocation/location_arbitrator.cc
@@ -182,7 +182,7 @@ LocationArbitrator::NewNetworkLocationPr
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
