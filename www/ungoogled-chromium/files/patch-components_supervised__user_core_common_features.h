--- components/supervised_user/core/common/features.h.orig	2023-12-23 12:33:28 UTC
+++ components/supervised_user/core/common/features.h
@@ -24,7 +24,7 @@ BASE_DECLARE_FEATURE(kEnableManagedByParentUi);
 extern const base::FeatureParam<std::string> kManagedByParentUiMoreInfoUrl;
 BASE_DECLARE_FEATURE(kClearingCookiesKeepsSupervisedUsersSignedIn);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #endif
 
