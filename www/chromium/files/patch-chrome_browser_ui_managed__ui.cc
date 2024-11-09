--- chrome/browser/ui/managed_ui.cc.orig	2024-10-22 08:31:56 UTC
+++ chrome/browser/ui/managed_ui.cc
@@ -435,7 +435,7 @@ std::optional<std::string> GetDeviceManagerIdentity() 
       g_browser_process->platform_part()->browser_policy_connector_ash();
   return connector->GetEnterpriseDomainManager();
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string custom_management_label =
       g_browser_process->local_state()
           ? g_browser_process->local_state()->GetString(
@@ -469,7 +469,7 @@ std::optional<std::string> GetAccountManagerIdentity(P
                policy::EnterpriseManagementAuthority::CLOUD))
     return std::nullopt;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string custom_management_label =
       profile->GetPrefs()->GetString(prefs::kEnterpriseCustomLabel);
   if (!custom_management_label.empty()) {
