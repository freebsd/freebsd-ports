--- components/network_session_configurator/browser/network_session_configurator.cc.orig	2020-07-07 21:58:15 UTC
+++ components/network_session_configurator/browser/network_session_configurator.cc
@@ -703,7 +703,7 @@ net::URLRequestContextBuilder::HttpCacheParams::Type C
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
