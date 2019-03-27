--- src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc
@@ -591,7 +591,7 @@ net::URLRequestContextBuilder::HttpCacheParams::Type C
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
