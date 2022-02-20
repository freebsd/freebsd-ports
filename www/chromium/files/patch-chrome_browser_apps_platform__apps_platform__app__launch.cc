--- chrome/browser/apps/platform_apps/platform_app_launch.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.cc
@@ -17,7 +17,7 @@
 #include "extensions/common/constants.h"
 #include "extensions/common/extension.h"
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_window.h"
@@ -122,7 +122,7 @@ bool OpenExtensionApplicationTab(Profile* profile, con
   return app_tab != nullptr;
 }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 bool OpenDeprecatedApplicationPrompt(Profile* profile,
                                      const std::string& app_id) {
   if (!extensions::IsExtensionUnsupportedDeprecatedApp(profile, app_id))
