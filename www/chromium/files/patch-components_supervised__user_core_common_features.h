--- components/supervised_user/core/common/features.h.orig	2024-07-30 11:12:21 UTC
+++ components/supervised_user/core/common/features.h
@@ -25,7 +25,7 @@ BASE_DECLARE_FEATURE(
 // Applies new informative strings during the parental extension approval flow.
 BASE_DECLARE_FEATURE(kUpdatedSupervisedUserExtensionApprovalStrings);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #endif
 
@@ -53,7 +53,7 @@ bool IsSupervisedUserSkipParentApprovalToInstallExtens
 // Only affects Desktop platforms.
 BASE_DECLARE_FEATURE(kCustomWebSignInInterceptForSupervisedUsers);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // This hides the following guest mode entry points for supervised users:
 //
 // * In the Profile menu for supervised profiles
