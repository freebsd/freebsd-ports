--- components/password_manager/core/common/password_manager_pref_names.h.orig	2026-01-14 08:33:23 UTC
+++ components/password_manager/core/common/password_manager_pref_names.h
@@ -59,7 +59,7 @@ inline constexpr char kCredentialProviderEnabledOnStar
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 // Boolean pref controlled by the DeletingUndecryptablePasswordsEnabled policy.
 // If set to false it blocks deleting undecryptable passwords, otherwise the
 // deletion can happen.
@@ -217,7 +217,7 @@ inline constexpr char kProfileStoreDateLastUsedForFill
 inline constexpr char kAccountStoreDateLastUsedForFilling[] =
     "password_manager.account_store_date_last_used_for_filling";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Integer indicating how many times user saw biometric authentication before
 // filling promo.
 inline constexpr char kBiometricAuthBeforeFillingPromoShownCounter[] =
@@ -253,7 +253,7 @@ inline constexpr char kPasswordManagerPromoCardsList[]
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
@@ -286,7 +286,7 @@ inline constexpr char kLastNegativePasswordChangeTimes
     "password_manager.last_negative_password_change_timestamp";
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // List of urls for which password manager is disabled/blocked.
 inline constexpr char kPasswordManagerBlocklist[] =
     "password_manager.password_manager_blocklist";
