--- components/supervised_user/core/common/features.h.orig	2024-03-22 14:16:19 UTC
+++ components/supervised_user/core/common/features.h
@@ -28,7 +28,7 @@ extern const base::FeatureParam<std::string> kManagedB
 BASE_DECLARE_FEATURE(
     kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #endif
 
