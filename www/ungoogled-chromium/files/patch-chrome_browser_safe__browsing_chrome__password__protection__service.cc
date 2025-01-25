--- chrome/browser/safe_browsing/chrome_password_protection_service.cc.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/safe_browsing/chrome_password_protection_service.cc
@@ -1247,7 +1247,7 @@ std::string ChromePasswordProtectionService::GetOrgani
     ReusedPasswordAccountType password_type) const {
   if (base::FeatureList::IsEnabled(
           safe_browsing::kEnterprisePasswordReuseUiRefresh)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return GetPrefs()->GetString(prefs::kEnterpriseCustomLabel);
 #else
     return std::string();
