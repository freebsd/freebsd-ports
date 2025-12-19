--- src/3rdparty/chromium/components/supervised_user/core/common/features.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/supervised_user/core/common/features.h
@@ -30,7 +30,7 @@ BASE_DECLARE_FEATURE(kUpdatedSupervisedUserExtensionAp
 // Applies new informative strings during the parental extension approval flow.
 BASE_DECLARE_FEATURE(kUpdatedSupervisedUserExtensionApprovalStrings);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #endif
 
@@ -60,7 +60,7 @@ BASE_DECLARE_FEATURE(kCustomProfileStringsForSupervise
 
 // Displays a Family Link kite badge on the supervised user avatar in various
 // surfaces.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kShowKiteForSupervisedUsers);
 #endif
 
@@ -68,7 +68,7 @@ BASE_DECLARE_FEATURE(kForceSafeSearchForUnauthenticate
 // unauthenticated (e.g. signed out of the content area) account.
 BASE_DECLARE_FEATURE(kForceSafeSearchForUnauthenticatedSupervisedUsers);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Uses supervised user strings on the signout dialog.
 BASE_DECLARE_FEATURE(kEnableSupervisedUserVersionSignOutDialog);
 
