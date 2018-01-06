--- src/3rdparty/chromium/net/tools/get_server_time/get_server_time.cc.orig	2017-01-26 00:49:16 UTC
+++ src/3rdparty/chromium/net/tools/get_server_time/get_server_time.cc
@@ -46,7 +46,7 @@
 
 #if defined(OS_MACOSX)
 #include "base/mac/scoped_nsautorelease_pool.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "net/proxy/proxy_config.h"
 #include "net/proxy/proxy_config_service_fixed.h"
 #endif
@@ -142,7 +142,7 @@ class PrintingLogObserver : public net::
 std::unique_ptr<net::URLRequestContext> BuildURLRequestContext(
     net::NetLog* net_log) {
   net::URLRequestContextBuilder builder;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
