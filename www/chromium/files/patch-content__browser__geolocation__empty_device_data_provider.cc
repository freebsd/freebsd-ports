--- content/browser/geolocation/empty_device_data_provider.cc.orig	2012-11-27 21:01:24.000000000 -0500
+++ content/browser/geolocation/empty_device_data_provider.cc	2012-12-06 15:40:02.698863304 -0500
@@ -5,7 +5,7 @@
 #include "content/browser/geolocation/empty_device_data_provider.h"
 
 // Only define for platforms that lack a real wifi data provider.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_FREEBSD)
 // static
 template<>
 WifiDataProviderImplBase* WifiDataProvider::DefaultFactoryFunction() {
