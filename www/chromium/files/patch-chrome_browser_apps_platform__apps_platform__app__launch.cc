--- chrome/browser/apps/platform_apps/platform_app_launch.cc.orig	2021-09-24 18:17:35 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.cc
@@ -17,13 +17,13 @@
 #include "extensions/common/constants.h"
 #include "extensions/common/extension.h"
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_window.h"
 #include "chrome/browser/web_applications/extension_status_utils.h"
 #include "chrome/common/webui_url_constants.h"
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace apps {
 
@@ -122,7 +122,7 @@ bool OpenExtensionApplicationTab(Profile* profile, con
   return app_tab != nullptr;
 }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 bool OpenDeprecatedApplicationPrompt(Profile* profile,
                                      const std::string& app_id) {
   if (!extensions::IsExtensionUnsupportedDeprecatedApp(profile, app_id))
@@ -142,7 +142,7 @@ bool OpenDeprecatedApplicationPrompt(Profile* profile,
   // TODO(crbug.com/1225779): Show the deprecated apps dialog.
   return true;
 }
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 bool OpenExtensionApplicationWithReenablePrompt(
     Profile* profile,
