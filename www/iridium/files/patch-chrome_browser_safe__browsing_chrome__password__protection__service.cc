--- chrome/browser/safe_browsing/chrome_password_protection_service.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/safe_browsing/chrome_password_protection_service.cc
@@ -1290,7 +1290,7 @@ std::string ChromePasswordProtectionService::GetOrgani
     ReusedPasswordAccountType password_type) const {
   if (base::FeatureList::IsEnabled(
           safe_browsing::kEnterprisePasswordReuseUiRefresh)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return GetPrefs()->GetString(prefs::kEnterpriseCustomLabelForProfile);
 #else
     return std::string();
