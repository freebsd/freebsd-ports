--- services/device/geolocation/location_arbitrator.cc.orig	2018-12-13 22:21:38.804321000 +0100
+++ services/device/geolocation/location_arbitrator.cc	2018-12-13 22:22:16.348629000 +0100
@@ -164,7 +164,7 @@
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
