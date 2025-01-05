--- src/3rdparty/chromium/components/supervised_user/core/common/features.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/components/supervised_user/core/common/features.cc
@@ -64,7 +64,7 @@ bool IsLocalWebApprovalsEnabled() {
 // particular aspects. If one or more of these sub-feature flags are enabled,
 // then child account detection logic is implicitly enabled.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFilterWebsitesForSupervisedUsersOnDesktopAndIOS,
              "FilterWebsitesForSupervisedUsersOnDesktopAndIOS",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -74,7 +74,7 @@ BASE_FEATURE(kFilterWebsitesForSupervisedUsersOnDeskto
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSupervisedPrefsControlledBySupervisedStore,
              "SupervisedPrefsControlledBySupervisedStore",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -86,7 +86,7 @@ BASE_FEATURE(kSupervisedPrefsControlledBySupervisedSto
 
 // Whether to display a "Managed by your parent" or similar text for supervised
 // users in various UI surfaces.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableManagedByParentUi,
              "EnableManagedByParentUi",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -96,7 +96,7 @@ BASE_FEATURE(kEnableManagedByParentUi,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -115,7 +115,7 @@ bool CanDisplayFirstTimeInterstitialBanner() {
 
 // When enabled non-syncing signed in supervised users will not be signed out of
 // their google account when cookies are cleared
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kClearingCookiesKeepsSupervisedUsersSignedIn,
              "ClearingCookiesKeepsSupervisedUsersSignedIn",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -162,7 +162,7 @@ bool IsChildAccountSupervisionEnabled() {
   return base::FeatureList::IsEnabled(
              supervised_user::
                  kFilterWebsitesForSupervisedUsersOnDesktopAndIOS) ||
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
          base::FeatureList::IsEnabled(
              supervised_user::
                  kEnableExtensionsPermissionsForSupervisedUsersOnDesktop) ||
