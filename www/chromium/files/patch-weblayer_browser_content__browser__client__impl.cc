--- weblayer/browser/content_browser_client_impl.cc.orig	2020-03-03 18:54:07 UTC
+++ weblayer/browser/content_browser_client_impl.cc
@@ -65,7 +65,7 @@
 #include "weblayer/browser/safe_browsing/safe_browsing_service.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -232,7 +232,7 @@ ContentBrowserClientImpl::CreateNetworkContext(
 
 void ContentBrowserClientImpl::OnNetworkServiceCreated(
     network::mojom::NetworkService* network_service) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   network::mojom::CryptConfigPtr config = network::mojom::CryptConfig::New();
   content::GetNetworkService()->SetCryptConfig(std::move(config));
 #endif
@@ -371,7 +371,7 @@ SafeBrowsingService* ContentBrowserClientImpl::GetSafe
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 void ContentBrowserClientImpl::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -405,7 +405,7 @@ void ContentBrowserClientImpl::GetAdditionalMappedFile
     mappings->Share(service_manager::kCrashDumpSignal, crash_signal_fd);
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
 bool ContentBrowserClientImpl::ShouldOverrideUrlLoading(
