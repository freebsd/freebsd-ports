--- net/url_request/url_request_context_builder.cc.orig	2017-04-19 19:06:36 UTC
+++ net/url_request/url_request_context_builder.cc
@@ -327,7 +327,7 @@ std::unique_ptr<URLRequestContext> URLRe
   if (!proxy_service_) {
     // TODO(willchan): Switch to using this code when
     // ProxyService::CreateSystemProxyConfigService()'s signature doesn't suck.
-#if !defined(OS_LINUX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     if (!proxy_config_service_) {
       proxy_config_service_ = ProxyService::CreateSystemProxyConfigService(
           base::ThreadTaskRunnerHandle::Get().get(),
