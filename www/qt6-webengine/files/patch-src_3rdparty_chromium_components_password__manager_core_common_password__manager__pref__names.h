--- src/3rdparty/chromium/components/password_manager/core/common/password_manager_pref_names.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/password_manager/core/common/password_manager_pref_names.h
@@ -50,7 +50,7 @@ inline constexpr char kCredentialProviderEnabledOnStar
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 // Boolean pref controlled by the DeletingUndecryptablePasswordsEnabled policy.
 // If set to false it blocks deleting undecryptable passwords, otherwise the
 // deletion can happen.
@@ -359,7 +359,7 @@ inline constexpr char kPasswordSharingEnabled[] =
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
