--- components/network_session_configurator/browser/network_session_configurator.cc.orig	2017-12-24 12:05:09.663658000 +0100
+++ components/network_session_configurator/browser/network_session_configurator.cc	2017-12-24 12:05:50.949666000 +0100
@@ -460,7 +460,7 @@
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
