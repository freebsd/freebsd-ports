--- src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc
@@ -807,7 +807,7 @@ net::URLRequestContextBuilder::HttpCacheParams::Type C
   }
 #endif  // #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
