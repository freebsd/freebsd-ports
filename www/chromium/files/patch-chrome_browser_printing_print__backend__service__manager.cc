--- chrome/browser/printing/print_backend_service_manager.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -420,7 +420,7 @@ uint32_t PrintBackendServiceManager::RegisterClient(
       query_clients_.insert(client_id);
       break;
     case ClientType::kQueryWithUi:
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
       DCHECK_EQ(query_with_ui_clients_.size(), 0u);
 #endif
       query_with_ui_clients_.insert(client_id);
@@ -644,7 +644,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       break;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (query_with_ui_clients_.size() > 1)
         return absl::nullopt;
@@ -701,7 +701,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (!query_with_ui_clients_.empty())
         return absl::nullopt;
