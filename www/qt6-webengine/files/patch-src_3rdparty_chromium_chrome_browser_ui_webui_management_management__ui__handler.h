--- src/3rdparty/chromium/chrome/browser/ui/webui/management/management_ui_handler.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/browser/ui/webui/management/management_ui_handler.h
@@ -30,7 +30,7 @@ class PolicyService;
 class PolicyService;
 }  // namespace policy
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace device_signals {
 class UserPermissionService;
 }  // namespace device_signals
@@ -71,7 +71,7 @@ class ManagementUIHandler : public content::WebUIMessa
   base::Value::List GetManagedWebsitesInfo(Profile* profile) const;
   base::Value::List GetApplicationsInfo(Profile* profile) const;
   virtual policy::PolicyService* GetPolicyService();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual device_signals::UserPermissionService* GetUserPermissionService();
   base::Value::Dict GetDeviceSignalGrantedMessage();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
