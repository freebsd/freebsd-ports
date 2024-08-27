--- chrome/browser/extensions/api/management/chrome_management_api_delegate.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/extensions/api/management/chrome_management_api_delegate.cc
@@ -417,7 +417,7 @@ bool ChromeManagementAPIDelegate::LaunchAppFunctionDel
   apps::LaunchContainer launch_container =
       GetLaunchContainer(extensions::ExtensionPrefs::Get(context), extension);
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile,
                                                       extension->id())) {
     return false;
