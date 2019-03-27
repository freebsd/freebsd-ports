--- src/3rdparty/chromium/net/url_request/url_request_context_builder.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/url_request/url_request_context_builder.cc
@@ -512,7 +512,7 @@ std::unique_ptr<URLRequestContext> URLRequestContextBu
   }
 
   if (!proxy_resolution_service_) {
-#if !defined(OS_LINUX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     // TODO(willchan): Switch to using this code when
     // ProxyResolutionService::CreateSystemProxyConfigService()'s signature
     // doesn't suck.
