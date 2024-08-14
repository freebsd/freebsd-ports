--- components/password_manager/core/browser/password_manager.cc.orig	2024-07-30 11:12:21 UTC
+++ components/password_manager/core/browser/password_manager.cc
@@ -386,7 +386,7 @@ void PasswordManager::RegisterProfilePrefs(
       prefs::kAutofillableCredentialsAccountStoreLoginDatabase, false);
 #endif  // BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)
   registry->RegisterBooleanPref(prefs::kPasswordSharingEnabled, true);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kRelaunchChromeBubbleDismissedCounter,
                                 0);
 #endif
