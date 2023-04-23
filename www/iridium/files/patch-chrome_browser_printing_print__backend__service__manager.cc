--- chrome/browser/printing/print_backend_service_manager.cc.orig	2023-04-22 17:45:15 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -547,7 +547,7 @@ PrintBackendServiceManager::RegisterClient(
       query_clients_.insert(client_id);
       break;
     case ClientType::kQueryWithUi:
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
       if (!query_with_ui_clients_.empty())
         return absl::nullopt;
 #endif
@@ -813,7 +813,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       break;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (query_with_ui_clients_.size() > 1)
         return absl::nullopt;
@@ -870,7 +870,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return absl::nullopt;
