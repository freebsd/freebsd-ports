--- chrome/browser/ui/browser_dialogs.h.orig	2021-09-24 04:26:00 UTC
+++ chrome/browser/ui/browser_dialogs.h
@@ -24,7 +24,7 @@
 #include "ui/gfx/native_widget_types.h"
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/web_applications/components/web_app_id.h"
 #endif
 
@@ -78,7 +78,7 @@ struct SelectedFileInfo;
 }  // namespace ui
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 namespace web_app {
 struct UrlHandlerLaunchParams;
 }
@@ -175,7 +175,7 @@ void ShowWebAppProtocolHandlerIntentPicker(
 #endif  // !defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 // Callback that runs when the Web App URL Handler Intent Picker dialog is
 // closed. `accepted` is true when the dialog is accepted, false otherwise.
 // `launch_params` contains information of the app that is selected to open by
