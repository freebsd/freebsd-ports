--- components/supervised_user/core/common/features.cc.orig	2024-03-22 14:16:19 UTC
+++ components/supervised_user/core/common/features.cc
@@ -66,7 +66,7 @@ bool IsLocalWebApprovalsEnabled() {
 BASE_FEATURE(kFilterWebsitesForSupervisedUsersOnDesktopAndIOS,
              "FilterWebsitesForSupervisedUsersOnDesktopAndIOS",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -74,7 +74,7 @@ BASE_FEATURE(kFilterWebsitesForSupervisedUsersOnDeskto
 
 BASE_FEATURE(kSupervisedPrefsControlledBySupervisedStore,
              "SupervisedPrefsControlledBySupervisedStore",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -84,7 +84,7 @@ BASE_FEATURE(kSupervisedPrefsControlledBySupervisedSto
 // users in various UI surfaces.
 BASE_FEATURE(kEnableManagedByParentUi,
              "EnableManagedByParentUi",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -94,7 +94,7 @@ BASE_FEATURE(kEnableSupervisedUserSkipParentApprovalTo
              "EnableSupervisedUserSkipParentApprovalToInstallExtensions",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -143,7 +143,7 @@ bool IsChildAccountSupervisionEnabled() {
   return base::FeatureList::IsEnabled(
              supervised_user::
                  kFilterWebsitesForSupervisedUsersOnDesktopAndIOS) ||
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
          base::FeatureList::IsEnabled(
              supervised_user::
                  kEnableExtensionsPermissionsForSupervisedUsersOnDesktop) ||
