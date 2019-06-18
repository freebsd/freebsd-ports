--- net/tools/cert_verify_tool/cert_verify_tool.cc.orig	2019-03-11 22:01:01 UTC
+++ net/tools/cert_verify_tool/cert_verify_tool.cc
@@ -27,7 +27,7 @@
 #include "net/url_request/url_request_context_builder.h"
 #include "net/url_request/url_request_context_getter.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -46,7 +46,7 @@ void SetUpOnNetworkThread(std::unique_ptr<net::URLRequ
                           base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
