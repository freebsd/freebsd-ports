--- chrome/browser/printing/print_backend_service_manager.cc.orig	2024-02-25 20:22:18 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -34,7 +34,7 @@
 #include "printing/printing_context.h"
 #include "printing/printing_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #endif
 
@@ -853,7 +853,7 @@ PrintBackendServiceManager::GetServiceFromBundle(
         host.BindNewPipeAndPassReceiver(),
         content::ServiceProcessHost::Options()
             .WithDisplayName(IDS_UTILITY_PROCESS_PRINT_BACKEND_SERVICE_NAME)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
             .WithExtraCommandLineSwitches({switches::kMessageLoopTypeUi})
 #endif
             .Pass());
@@ -1026,7 +1026,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return std::nullopt;
