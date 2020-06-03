--- components/network_session_configurator/browser/network_session_configurator.cc.orig	2020-05-13 18:40:26 UTC
+++ components/network_session_configurator/browser/network_session_configurator.cc
@@ -719,7 +719,7 @@ net::URLRequestContextBuilder::HttpCacheParams::Type C
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
