--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2024-11-16 12:20:41 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -57,7 +57,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/web_ui_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -345,7 +345,7 @@ void ManagementUIHandler::AddReportingInfo(base::Value
       report_sources->Append(std::move(data));
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto device_signal_data = GetDeviceSignalGrantedMessage();
     if (!device_signal_data.empty()) {
       report_sources->Append(std::move(device_signal_data));
@@ -367,7 +367,7 @@ void ManagementUIHandler::AddReportingInfo(base::Value
       report_sources->Append(std::move(data));
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto device_signal_data = GetDeviceSignalGrantedMessage();
     if (!device_signal_data.empty()) {
       report_sources->Append(std::move(device_signal_data));
@@ -551,7 +551,7 @@ policy::PolicyService* ManagementUIHandler::GetPolicyS
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
