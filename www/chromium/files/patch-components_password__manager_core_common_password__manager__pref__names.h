--- components/password_manager/core/common/password_manager_pref_names.h.orig	2024-09-30 07:45:04 UTC
+++ components/password_manager/core/common/password_manager_pref_names.h
@@ -41,7 +41,7 @@ inline constexpr char kCredentialProviderEnabledOnStar
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 // Boolean pref controlled by the DeletingUndecryptablePasswordsEnabled policy.
 // If set to false it blocks deleting undecryptable passwords, otherwise the
 // deletion can happen.
@@ -333,7 +333,7 @@ inline constexpr char kAutofillableCredentialsAccountS
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
