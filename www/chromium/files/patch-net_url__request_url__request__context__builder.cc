--- net/url_request/url_request_context_builder.cc.orig	2022-02-07 13:39:41 UTC
+++ net/url_request/url_request_context_builder.cc
@@ -424,7 +424,7 @@ std::unique_ptr<URLRequestContext> URLRequestContextBu
   }
 
   if (!proxy_resolution_service_) {
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID) && !defined(OS_BSD)
     // TODO(willchan): Switch to using this code when
     // ConfiguredProxyResolutionService::CreateSystemProxyConfigService()'s
     // signature doesn't suck.
