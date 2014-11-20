--- content/browser/geolocation/location_arbitrator_impl.cc.orig	2014-10-10 08:54:14 UTC
+++ content/browser/geolocation/location_arbitrator_impl.cc
@@ -159,7 +159,7 @@
 }
 
 LocationProvider* LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD)
   return NULL;
 #else
   return content::NewSystemLocationProvider();
