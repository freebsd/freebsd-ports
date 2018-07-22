--- net/url_request/url_request_context_builder.cc.orig	2018-06-13 00:10:23.000000000 +0200
+++ net/url_request/url_request_context_builder.cc	2018-07-19 16:09:43.508974000 +0200
@@ -506,7 +506,7 @@
   }
 
   if (!proxy_resolution_service_) {
-#if !defined(OS_LINUX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     // TODO(willchan): Switch to using this code when
     // ProxyResolutionService::CreateSystemProxyConfigService()'s signature
     // doesn't suck.
