--- content/browser/geolocation/location_arbitrator_impl.cc.orig	2016-05-11 19:02:20 UTC
+++ content/browser/geolocation/location_arbitrator_impl.cc
@@ -163,7 +163,7 @@ LocationProvider* LocationArbitratorImpl
 }
 
 LocationProvider* LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD)
   return NULL;
 #else
   return content::NewSystemLocationProvider();
