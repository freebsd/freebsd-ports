--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -81,7 +81,7 @@
 #include "chrome/browser/ui/managed_ui.h"  // nogncheck crbug.com/40147906
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -205,7 +205,7 @@ void AddThreatProtectionPermission(const char* title,
 }
 
 bool IsSaasReportingEnabled(content::WebUI* web_ui) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return !Profile::FromWebUI(web_ui)
               ->GetPrefs()
               ->GetList(enterprise_reporting::kSaasUsageDomainUrlsForProfile)
@@ -409,7 +409,7 @@ void ManagementUIHandler::AddBrowserReportingInfo(
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -444,7 +444,7 @@ void ManagementUIHandler::AddProfileReportingInfo(
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -632,7 +632,7 @@ policy::PolicyService* ManagementUIHandler::GetPolicyS
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
