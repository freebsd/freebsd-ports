--- net/url_request/url_request_context_builder.cc.orig	2016-12-16 03:18:23.560330000 +0000
+++ net/url_request/url_request_context_builder.cc	2016-12-16 03:19:00.302261000 +0000
@@ -326,7 +326,7 @@
   if (!proxy_service_) {
     // TODO(willchan): Switch to using this code when
     // ProxyService::CreateSystemProxyConfigService()'s signature doesn't suck.
-#if !defined(OS_LINUX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     if (!proxy_config_service_) {
       proxy_config_service_ = ProxyService::CreateSystemProxyConfigService(
           base::ThreadTaskRunnerHandle::Get().get(),
