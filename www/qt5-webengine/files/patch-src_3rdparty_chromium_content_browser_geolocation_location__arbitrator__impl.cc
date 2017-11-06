--- src/3rdparty/chromium/content/browser/geolocation/location_arbitrator_impl.cc.orig	2017-04-19 16:57:24 UTC
+++ src/3rdparty/chromium/content/browser/geolocation/location_arbitrator_impl.cc
@@ -174,7 +174,7 @@ LocationProvider* LocationArbitratorImpl
 }
 
 LocationProvider* LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return NULL;
 #else
   return content::NewSystemLocationProvider();
