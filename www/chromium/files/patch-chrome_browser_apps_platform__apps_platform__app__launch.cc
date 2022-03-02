--- chrome/browser/apps/platform_apps/platform_app_launch.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.cc
@@ -18,7 +18,7 @@
 #include "extensions/common/constants.h"
 #include "extensions/common/extension.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_window.h"
@@ -121,7 +121,7 @@ bool OpenExtensionApplicationTab(Profile* profile, con
   return app_tab != nullptr;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenDeprecatedApplicationPrompt(Profile* profile,
                                      const std::string& app_id) {
   if (!extensions::IsExtensionUnsupportedDeprecatedApp(profile, app_id))
