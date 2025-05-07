--- components/supervised_user/core/common/features.cc.orig	2025-05-06 12:23:00 UTC
+++ components/supervised_user/core/common/features.cc
@@ -36,7 +36,7 @@ BASE_FEATURE(kAllowSubframeLocalWebApprovals,
 #endif
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const int kLocalWebApprovalBottomSheetLoadTimeoutDefaultValueMs = 5000;
 
 const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs{
@@ -45,7 +45,7 @@ const base::FeatureParam<int> kLocalWebApprovalBottomS
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableLocalWebApprovalErrorDialog,
              "EnableLocalWebApprovalErrorDialog",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -97,7 +97,7 @@ BASE_FEATURE(kUpdatedSupervisedUserExtensionApprovalSt
              "UpdatedSupervisedUserExtensionApprovalStrings",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -112,7 +112,7 @@ bool IsSupervisedUserSkipParentApprovalToInstallExtens
 #if BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool skipParentApprovalEnabled = base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
   bool permissionExtensionsForSupervisedUsersEnabled =
@@ -129,7 +129,7 @@ bool IsSupervisedUserSkipParentApprovalToInstallExtens
 }
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kCustomProfileStringsForSupervisedUsers,
              "CustomProfileStringsForSupervisedUsers",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -141,13 +141,13 @@ BASE_FEATURE(kShowKiteForSupervisedUsers,
 
 BASE_FEATURE(kForceSafeSearchForUnauthenticatedSupervisedUsers,
              "ForceSafeSearchForUnauthenticatedSupervisedUsers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              "EnableSupervisedUserVersionSignOutDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -169,7 +169,7 @@ BASE_FEATURE(kExemptYouTubeInfrastructureFromBlocking,
 // platform #defines.
 BASE_FEATURE(kUncredentialedFilteringFallbackForSupervisedUsers,
              "UncredentialedFilteringFallbackForSupervisedUsers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
