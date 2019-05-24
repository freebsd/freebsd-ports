--- headless/lib/browser/headless_request_context_manager.cc.orig	2019-04-30 22:22:49 UTC
+++ headless/lib/browser/headless_request_context_manager.cc
@@ -34,7 +34,7 @@ namespace headless {
 
 namespace {
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 static char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -80,7 +80,7 @@ net::NetworkTrafficAnnotationTag GetProxyConfigTraffic
   return traffic_annotation;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 ::network::mojom::CryptConfigPtr BuildCryptConfigOnce(
     const base::FilePath& user_data_path) {
   static bool done_once = false;
@@ -289,7 +289,7 @@ HeadlessRequestContextManager::HeadlessRequestContextM
     proxy_config_monitor_ =
         std::make_unique<HeadlessProxyConfigMonitor>(proxy_monitor_task_runner);
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   crypt_config_ = BuildCryptConfigOnce(user_data_path_);
   if (network_service_enabled_ && crypt_config_)
     content::GetNetworkService()->SetCryptConfig(std::move(crypt_config_));
@@ -365,7 +365,7 @@ void HeadlessRequestContextManager::InitializeOnIO() {
                                   std::move(protocol_handler.second));
     }
     protocol_handlers_.clear();
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     if (crypt_config_) {
       content::GetNetworkServiceImpl()->SetCryptConfig(
           std::move(crypt_config_));
