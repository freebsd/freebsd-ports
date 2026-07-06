--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -74,7 +74,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/web_ui_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -197,7 +197,7 @@ void AddThreatProtectionPermission(const char* title,
 #endif  // BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
 
 bool IsSaasReportingEnabled(content::WebUI* web_ui) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return !Profile::FromWebUI(web_ui)
               ->GetPrefs()
               ->GetList(enterprise_reporting::kSaasUsageDomainUrlsForProfile)
@@ -398,7 +398,7 @@ void ManagementUIHandler::AddBrowserReportingInfo(
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -430,7 +430,7 @@ void ManagementUIHandler::AddProfileReportingInfo(
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -620,7 +620,7 @@ policy::PolicyService* ManagementUIHandler::GetPolicyS
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
