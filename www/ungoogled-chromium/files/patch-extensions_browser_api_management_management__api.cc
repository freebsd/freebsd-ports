--- extensions/browser/api/management/management_api.cc.orig	2023-12-23 12:33:28 UTC
+++ extensions/browser/api/management/management_api.cc
@@ -278,7 +278,7 @@ bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS)
   // ChromeOS devices have this feature already shipped.
   return true;
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       supervised_user::kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #else
