--- content/browser/geolocation/empty_wifi_data_provider.cc.orig	2013-11-08 07:41:47.000000000 +0100
+++ content/browser/geolocation/empty_wifi_data_provider.cc	2013-11-14 17:33:23.000000000 +0100
@@ -19,7 +19,7 @@
 }
 
 // Only define for platforms that lack a real wifi data provider.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_FREEBSD)
 // static
 WifiDataProviderImplBase* WifiDataProvider::DefaultFactoryFunction() {
   return new EmptyWifiDataProvider();
