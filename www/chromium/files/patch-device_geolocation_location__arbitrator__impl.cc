--- device/geolocation/location_arbitrator_impl.cc.orig	2016-10-06 04:02:19.000000000 +0300
+++ device/geolocation/location_arbitrator_impl.cc	2016-10-14 20:31:25.130350000 +0300
@@ -167,7 +167,7 @@
 
 std::unique_ptr<LocationProvider>
 LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
