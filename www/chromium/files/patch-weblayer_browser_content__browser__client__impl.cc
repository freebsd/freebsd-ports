--- weblayer/browser/content_browser_client_impl.cc.orig	2020-11-13 06:37:06 UTC
+++ weblayer/browser/content_browser_client_impl.cc
@@ -135,7 +135,7 @@
 #include "weblayer/browser/weblayer_factory_impl_android.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -382,7 +382,7 @@ void ContentBrowserClientImpl::ConfigureNetworkContext
 
 void ContentBrowserClientImpl::OnNetworkServiceCreated(
     network::mojom::NetworkService* network_service) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   network::mojom::CryptConfigPtr config = network::mojom::CryptConfig::New();
   content::GetNetworkService()->SetCryptConfig(std::move(config));
 #endif
