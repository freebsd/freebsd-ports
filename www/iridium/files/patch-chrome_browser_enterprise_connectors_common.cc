--- chrome/browser/enterprise/connectors/common.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/enterprise/connectors/common.cc
@@ -20,7 +20,7 @@
 #include "components/user_manager/user.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -306,7 +306,7 @@ std::string GetProfileEmail(Profile* profile) {
   std::string email =
       GetProfileEmail(IdentityManagerFactory::GetForProfile(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (email.empty()) {
     email = profile->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserEmail);
