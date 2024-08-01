--- components/supervised_user/core/common/features.cc.orig	2024-08-01 05:47:53 UTC
+++ components/supervised_user/core/common/features.cc
@@ -59,7 +59,7 @@ BASE_FEATURE(kUpdatedSupervisedUserExtensionApprovalSt
              "UpdatedSupervisedUserExtensionApprovalStrings",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -74,7 +74,7 @@ bool IsSupervisedUserSkipParentApprovalToInstallExtens
 #if BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool skipParentApprovalEnabled = base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
   bool permissionExtensionsForSupervisedUsersEnabled =
@@ -101,7 +101,7 @@ BASE_FEATURE(kCustomWebSignInInterceptForSupervisedUse
              "CustomWebSignInInterceptForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kHideGuestModeForSupervisedUsers,
              "HideGuestModeForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
