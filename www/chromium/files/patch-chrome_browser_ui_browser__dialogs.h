--- chrome/browser/ui/browser_dialogs.h.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/ui/browser_dialogs.h
@@ -27,7 +27,7 @@
 #include "ui/gfx/native_widget_types.h"
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/web_applications/web_app_id.h"
 #endif
 
@@ -81,7 +81,7 @@ struct SelectedFileInfo;
 }  // namespace ui
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 namespace web_app {
 struct UrlHandlerLaunchParams;
 }
@@ -208,7 +208,7 @@ void ShowWebAppFileLaunchDialog(const std::vector<base
 #endif  // !defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 // Callback that runs when the Web App URL Handler Intent Picker dialog is
 // closed. `accepted` is true when the dialog is accepted, false otherwise.
 // `launch_params` contains information of the app that is selected to open by
