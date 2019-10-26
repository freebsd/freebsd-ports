--- src/3rdparty/chromium/headless/lib/browser/headless_request_context_manager.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_request_context_manager.h
@@ -69,7 +69,7 @@ class HeadlessRequestContextManager {
   std::unique_ptr<HeadlessProxyConfigMonitor> proxy_config_monitor_;
   bool is_system_context_;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   ::network::mojom::CryptConfigPtr crypt_config_;
 #endif
 
