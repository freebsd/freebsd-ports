--- src/3rdparty/chromium/components/password_manager/core/browser/password_manager.cc.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/password_manager.cc
@@ -363,7 +363,7 @@ void PasswordManager::RegisterProfilePrefs(
   registry->RegisterListPref(prefs::kPasswordManagerPromoCardsList);
 #endif  // BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)
   registry->RegisterBooleanPref(prefs::kPasswordSharingEnabled, true);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kRelaunchChromeBubbleDismissedCounter,
                                 0);
 #endif
