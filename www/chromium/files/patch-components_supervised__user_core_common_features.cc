--- components/supervised_user/core/common/features.cc.orig	2025-01-15 09:18:26 UTC
+++ components/supervised_user/core/common/features.cc
@@ -60,7 +60,7 @@ BASE_FEATURE(kUpdatedSupervisedUserExtensionApprovalSt
              "UpdatedSupervisedUserExtensionApprovalStrings",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -75,7 +75,7 @@ bool IsSupervisedUserSkipParentApprovalToInstallExtens
 #if BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool skipParentApprovalEnabled = base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
   bool permissionExtensionsForSupervisedUsersEnabled =
@@ -96,13 +96,13 @@ BASE_FEATURE(kCustomProfileStringsForSupervisedUsers,
              "CustomProfileStringsForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShowKiteForSupervisedUsers,
              "ShowKiteForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kHideGuestModeForSupervisedUsers,
              "HideGuestModeForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -112,7 +112,7 @@ BASE_FEATURE(kForceSafeSearchForUnauthenticatedSupervi
              "ForceSafeSearchForUnauthenticatedSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kForceSupervisedUserReauthenticationForYouTube,
              "ForceSupervisedUserReauthenticationForYouTube",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -162,7 +162,7 @@ BASE_FEATURE(kReplaceSupervisionSystemCapabilitiesWith
 
 BASE_FEATURE(kFetchListFamilyMembersWithCapability,
              "FetchListFamilyMembersWithCapability",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
