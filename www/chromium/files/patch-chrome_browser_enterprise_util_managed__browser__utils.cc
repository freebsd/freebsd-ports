--- chrome/browser/enterprise/util/managed_browser_utils.cc.orig	2025-05-05 10:57:53 UTC
+++ chrome/browser/enterprise/util/managed_browser_utils.cc
@@ -222,7 +222,7 @@ void SetUserAcceptedAccountManagement(Profile* profile
       profile_manager->GetProfileAttributesStorage()
           .GetProfileAttributesWithPath(profile->GetPath());
   if (entry) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     SetEnterpriseProfileLabel(profile);
 #endif
     entry->SetUserAcceptedAccountManagement(accepted);
