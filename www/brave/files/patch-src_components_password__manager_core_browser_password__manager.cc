--- src/components/password_manager/core/browser/password_manager.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/password_manager/core/browser/password_manager.cc
@@ -615,12 +615,12 @@ void PasswordManager::RegisterProfilePre
   registry->RegisterListPref(prefs::kPasswordManagerPromoCardsList);
 #endif  // BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(prefs::kPasswordManagerBlocklist);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
   registry->RegisterBooleanPref(prefs::kPasswordSharingEnabled, true);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kRelaunchChromeBubbleDismissedCounter,
                                 0);
 #endif
@@ -633,7 +633,7 @@ void PasswordManager::RegisterProfilePre
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kDeletingUndecryptablePasswordsEnabled,
                                 true);
 #endif
@@ -663,7 +663,7 @@ void PasswordManager::RegisterLocalPrefs
   registry->RegisterBooleanPref(prefs::kOsPasswordBlank, false);
   registry->RegisterBooleanPref(prefs::kIsBiometricAvailable, false);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kHadBiometricsAvailable, false);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS)
   registry->RegisterListPref(prefs::kLocalPasswordHashDataList,
