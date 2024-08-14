--- components/password_manager/core/common/password_manager_pref_names.h.orig	2024-08-01 05:47:53 UTC
+++ components/password_manager/core/common/password_manager_pref_names.h
@@ -358,7 +358,7 @@ inline constexpr char kAutofillableCredentialsAccountS
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
