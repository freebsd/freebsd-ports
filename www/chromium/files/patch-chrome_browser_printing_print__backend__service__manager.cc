--- chrome/browser/printing/print_backend_service_manager.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -481,7 +481,7 @@ absl::optional<uint32_t> PrintBackendServiceManager::R
       query_clients_.insert(client_id);
       break;
     case ClientType::kQueryWithUi:
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
       if (!query_with_ui_clients_.empty())
         return absl::nullopt;
 #endif
@@ -706,7 +706,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       break;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (query_with_ui_clients_.size() > 1)
         return absl::nullopt;
@@ -763,7 +763,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (!query_with_ui_clients_.empty())
         return absl::nullopt;
