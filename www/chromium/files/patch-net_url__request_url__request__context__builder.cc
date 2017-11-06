--- net/url_request/url_request_context_builder.cc.orig	2017-07-25 21:04:59.000000000 +0200
+++ net/url_request/url_request_context_builder.cc	2017-08-02 14:44:51.403673000 +0200
@@ -435,7 +435,7 @@
   }
 
   if (!proxy_service_) {
-#if !defined(OS_LINUX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     // TODO(willchan): Switch to using this code when
     // ProxyService::CreateSystemProxyConfigService()'s signature doesn't suck.
     if (!proxy_config_service_) {
@@ -443,7 +443,7 @@
           base::ThreadTaskRunnerHandle::Get().get(),
           context->GetFileTaskRunner());
     }
-#endif  // !defined(OS_LINUX) && !defined(OS_ANDROID)
+#endif  // !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     proxy_service_ =
         CreateProxyService(std::move(proxy_config_service_), context.get(),
                            context->host_resolver(),
