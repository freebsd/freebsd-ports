--- net/url_request/url_request_context_builder.cc.orig	2025-05-06 12:23:00 UTC
+++ net/url_request/url_request_context_builder.cc
@@ -442,7 +442,7 @@ std::unique_ptr<URLRequestContext> URLRequestContextBu
   }
 
   if (!proxy_resolution_service_) {
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     // TODO(willchan): Switch to using this code when
     // ProxyConfigService::CreateSystemProxyConfigService()'s
     // signature doesn't suck.
