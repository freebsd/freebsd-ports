--- device/geolocation/location_arbitrator.cc.orig	2017-12-15 02:04:18.000000000 +0100
+++ device/geolocation/location_arbitrator.cc	2017-12-24 15:54:40.400280000 +0100
@@ -173,7 +173,7 @@
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
