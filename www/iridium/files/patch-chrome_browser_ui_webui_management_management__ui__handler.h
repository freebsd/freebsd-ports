--- chrome/browser/ui/webui/management/management_ui_handler.h.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.h
@@ -34,7 +34,7 @@ namespace enterprise_management {
 class GetUserEligiblePromotionsResponse;
 }  // namespace enterprise_management
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace device_signals {
 class UserPermissionService;
 }  // namespace device_signals
@@ -91,7 +91,7 @@ class ManagementUIHandler : public content::WebUIMessa
   base::Value::List GetManagedWebsitesInfo(Profile* profile) const;
   base::Value::List GetApplicationsInfo(Profile* profile) const;
   virtual policy::PolicyService* GetPolicyService();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual device_signals::UserPermissionService* GetUserPermissionService();
   base::Value::Dict GetDeviceSignalGrantedMessage();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
