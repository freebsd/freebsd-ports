--- ./content/browser/geolocation/location_arbitrator_impl.cc.orig	2014-08-20 21:02:48.000000000 +0200
+++ ./content/browser/geolocation/location_arbitrator_impl.cc	2014-08-22 15:06:25.000000000 +0200
@@ -160,7 +160,7 @@
 }
 
 LocationProvider* LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD)
   return NULL;
 #else
   return content::NewSystemLocationProvider();
