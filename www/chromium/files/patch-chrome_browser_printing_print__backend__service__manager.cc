--- chrome/browser/printing/print_backend_service_manager.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -37,7 +37,7 @@
 #include "printing/printing_context.h"
 #include "printing/printing_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -909,7 +909,7 @@ PrintBackendServiceManager::GetServiceFromBundle(
             << remote_id << "`";
 
     std::vector<std::string> extra_switches;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (auto* linux_ui = ui::LinuxUi::instance()) {
       extra_switches = linux_ui->GetCmdLineFlagsForCopy();
     }
@@ -1095,7 +1095,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return std::nullopt;
