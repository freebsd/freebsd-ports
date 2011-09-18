--- content/browser/geolocation/location_provider.cc.orig	2011-09-15 01:38:39.000000000 +0300
+++ content/browser/geolocation/location_provider.cc	2011-09-15 01:39:07.000000000 +0300
@@ -56,7 +56,7 @@
   }
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD) && !defined(OS_MACOSX) && !defined(OS_WIN)
 LocationProviderBase* NewSystemLocationProvider() {
   return NULL;
 }
