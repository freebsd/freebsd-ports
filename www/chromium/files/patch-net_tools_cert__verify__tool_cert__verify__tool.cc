--- net/tools/cert_verify_tool/cert_verify_tool.cc.orig	2020-07-07 21:57:40 UTC
+++ net/tools/cert_verify_tool/cert_verify_tool.cc
@@ -29,7 +29,7 @@
 #include "net/url_request/url_request_context_builder.h"
 #include "net/url_request/url_request_context_getter.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -46,7 +46,7 @@ void SetUpOnNetworkThread(
     base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
@@ -192,7 +192,7 @@ std::unique_ptr<CertVerifyImpl> CreateCertVerifyImplFr
     base::StringPiece impl_name,
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher,
     bool use_system_roots) {
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   if (impl_name == "platform") {
     if (!use_system_roots) {
       std::cerr << "WARNING: platform verifier not supported with "
