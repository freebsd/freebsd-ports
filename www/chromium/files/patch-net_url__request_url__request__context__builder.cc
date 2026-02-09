--- net/url_request/url_request_context_builder.cc.orig	2026-02-11 09:05:39 UTC
+++ net/url_request/url_request_context_builder.cc
@@ -451,7 +451,7 @@ std::unique_ptr<URLRequestContext> URLRequestContextBu
   }
 
   if (!proxy_resolution_service_) {
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     // TODO(willchan): Switch to using this code when
     // ProxyConfigService::CreateSystemProxyConfigService()'s
     // signature doesn't suck.
