--- chrome/browser/safe_browsing/chrome_password_protection_service.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/safe_browsing/chrome_password_protection_service.cc
@@ -1403,7 +1403,7 @@ std::string ChromePasswordProtectionService::GetOrgani
     ReusedPasswordAccountType password_type) const {
   if (base::FeatureList::IsEnabled(
           safe_browsing::kEnterprisePasswordReuseUiRefresh)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return GetPrefs()->GetString(prefs::kEnterpriseCustomLabelForProfile);
 #else
     return std::string();
