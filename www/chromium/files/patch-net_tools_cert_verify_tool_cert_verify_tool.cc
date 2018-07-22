--- net/tools/cert_verify_tool/cert_verify_tool.cc.orig	2018-07-19 22:18:26.747684000 +0200
+++ net/tools/cert_verify_tool/cert_verify_tool.cc	2018-07-19 22:18:48.374229000 +0200
@@ -26,7 +26,7 @@
 #include "net/url_request/url_request_context_builder.h"
 #include "net/url_request/url_request_context_getter.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -45,7 +45,7 @@
                           base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
