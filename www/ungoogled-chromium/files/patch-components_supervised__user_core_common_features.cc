--- components/supervised_user/core/common/features.cc.orig	2024-02-03 15:42:55 UTC
+++ components/supervised_user/core/common/features.cc
@@ -85,7 +85,7 @@ BASE_FEATURE(kEnableManagedByParentUi,
              "EnableManagedByParentUi",
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
