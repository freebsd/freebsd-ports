--- chrome/browser/safe_browsing/cloud_content_scanning/deep_scanning_utils.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/browser/safe_browsing/cloud_content_scanning/deep_scanning_utils.cc
@@ -16,7 +16,7 @@
 #include "components/crash/core/common/crash_key.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -416,7 +416,7 @@ std::string GetProfileEmail(Profile* profile) {
   std::string email =
       GetProfileEmail(IdentityManagerFactory::GetForProfile(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (email.empty()) {
     email = profile->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserEmail);
