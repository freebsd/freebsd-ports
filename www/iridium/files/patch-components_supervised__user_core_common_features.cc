--- components/supervised_user/core/common/features.cc.orig	2024-02-04 14:46:08 UTC
+++ components/supervised_user/core/common/features.cc
@@ -91,7 +91,7 @@ BASE_FEATURE(kEnableManagedByParentUi,
              "EnableManagedByParentUi",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -149,7 +149,7 @@ bool IsChildAccountSupervisionEnabled() {
   return base::FeatureList::IsEnabled(
              supervised_user::
                  kFilterWebsitesForSupervisedUsersOnDesktopAndIOS) ||
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
          base::FeatureList::IsEnabled(
              supervised_user::
                  kEnableExtensionsPermissionsForSupervisedUsersOnDesktop) ||
