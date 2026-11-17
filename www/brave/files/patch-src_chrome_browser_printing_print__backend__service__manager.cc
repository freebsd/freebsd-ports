--- src/chrome/browser/printing/print_backend_service_manager.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/printing/print_backend_service_manager.cc
@@ -35,7 +35,7 @@
 #include "printing/printing_context.h"
 #include "printing/printing_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -871,7 +871,7 @@ PrintBackendServiceManager::GetServiceFr
             << remote_id << "`";
 
     std::vector<std::string> extra_switches;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (auto* linux_ui = ui::LinuxUi::instance()) {
       extra_switches = linux_ui->GetCmdLineFlagsForCopy();
     }
@@ -1043,7 +1043,7 @@ PrintBackendServiceManager::DetermineIdl
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return std::nullopt;
