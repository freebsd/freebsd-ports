--- net/url_request/url_request_context_builder.cc.orig	2021-09-24 04:26:09 UTC
+++ net/url_request/url_request_context_builder.cc
@@ -431,7 +431,7 @@ std::unique_ptr<URLRequestContext> URLRequestContextBu
   }
 
   if (!proxy_resolution_service_) {
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID) && !defined(OS_BSD)
     // TODO(willchan): Switch to using this code when
     // ConfiguredProxyResolutionService::CreateSystemProxyConfigService()'s
     // signature doesn't suck.
@@ -440,7 +440,7 @@ std::unique_ptr<URLRequestContext> URLRequestContextBu
           ConfiguredProxyResolutionService::CreateSystemProxyConfigService(
               base::ThreadTaskRunnerHandle::Get().get());
     }
-#endif  // !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#endif  // !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID) && !defined(OS_BSD)
     proxy_resolution_service_ = CreateProxyResolutionService(
         std::move(proxy_config_service_), context.get(),
         context->host_resolver(), context->network_delegate(),
