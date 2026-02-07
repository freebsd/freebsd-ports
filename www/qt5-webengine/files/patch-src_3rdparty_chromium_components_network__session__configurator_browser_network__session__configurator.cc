--- src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc
@@ -749,7 +749,7 @@ net::URLRequestContextBuilder::HttpCacheParams::Type C
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
