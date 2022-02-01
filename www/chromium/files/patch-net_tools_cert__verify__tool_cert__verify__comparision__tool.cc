--- net/tools/cert_verify_tool/cert_verify_comparision_tool.cc.orig	2022-01-21 13:35:43 UTC
+++ net/tools/cert_verify_tool/cert_verify_comparision_tool.cc
@@ -35,7 +35,7 @@
 #include "net/url_request/url_request_context_builder.h"
 #include "net/url_request/url_request_context_getter.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -51,7 +51,7 @@ void SetUpOnNetworkThread(
     base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
@@ -123,7 +123,7 @@ class CertVerifyImpl {
 std::unique_ptr<CertVerifyImpl> CreateCertVerifyImplFromName(
     base::StringPiece impl_name,
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher) {
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   if (impl_name == "platform") {
     return std::make_unique<CertVerifyImpl>(
         "CertVerifyProc (system)", net::CertVerifyProc::CreateSystemVerifyProc(
