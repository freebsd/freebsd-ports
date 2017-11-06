--- net/tools/cert_verify_tool/verify_using_path_builder.cc.orig	2017-06-05 19:03:10 UTC
+++ net/tools/cert_verify_tool/verify_using_path_builder.cc
@@ -34,7 +34,7 @@
 #include "net/cert/internal/trust_store_nss.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "net/proxy/proxy_config.h"
 #include "net/proxy/proxy_config_service_fixed.h"
 #endif
@@ -187,7 +187,7 @@ void SetUpOnNetworkThread(std::unique_ptr<net::URLRequ
   // (similar to VERIFY_CERT_IO_ENABLED flag for CertVerifyProc).
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
