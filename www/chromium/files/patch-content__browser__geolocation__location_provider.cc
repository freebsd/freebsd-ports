--- content/browser/geolocation/location_provider.cc.orig	2012-07-18 10:01:25.000000000 +0300
+++ content/browser/geolocation/location_provider.cc	2012-07-25 21:04:42.000000000 +0300
@@ -56,7 +56,7 @@
   }
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN) && !defined OS_ANDROID
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN) && !defined OS_ANDROID && !defined(OS_FREEBSD)
 LocationProviderBase* NewSystemLocationProvider() {
   return NULL;
 }
