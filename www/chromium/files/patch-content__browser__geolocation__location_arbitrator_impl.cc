--- content/browser/geolocation/location_arbitrator_impl.cc.orig	2014-01-07 21:02:28.000000000 +0100
+++ content/browser/geolocation/location_arbitrator_impl.cc	2014-01-13 16:30:21.000000000 +0100
@@ -160,7 +160,7 @@
 }
 
 LocationProvider* LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD)
   return NULL;
 #else
   return content::NewSystemLocationProvider();
