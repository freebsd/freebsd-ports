--- components/network_session_configurator/browser/network_session_configurator.cc.orig	2019-04-30 22:22:42 UTC
+++ components/network_session_configurator/browser/network_session_configurator.cc
@@ -697,7 +697,7 @@ net::URLRequestContextBuilder::HttpCacheParams::Type C
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
