--- chrome/browser/ui/managed_ui.cc.orig	2025-02-19 07:43:18 UTC
+++ chrome/browser/ui/managed_ui.cc
@@ -442,7 +442,7 @@ std::optional<std::string> GetDeviceManagerIdentity() 
       g_browser_process->platform_part()->browser_policy_connector_ash();
   return connector->GetEnterpriseDomainManager();
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =
@@ -481,7 +481,7 @@ std::optional<std::string> GetAccountManagerIdentity(P
     return std::nullopt;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =
