--- chrome/browser/ui/browser_dialogs.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/browser_dialogs.h
@@ -26,7 +26,7 @@
 #include "ui/base/models/dialog_model.h"
 #include "ui/gfx/native_widget_types.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/web_applications/web_app_id.h"
 #endif
@@ -80,7 +80,7 @@ class WebDialogDelegate;
 struct SelectedFileInfo;
 }  // namespace ui
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 namespace web_app {
 struct UrlHandlerLaunchParams;
@@ -207,7 +207,7 @@ void ShowWebAppFileLaunchDialog(const std::vector<base
                                 WebAppLaunchAcceptanceCallback close_callback);
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 // Callback that runs when the Web App URL Handler Intent Picker dialog is
 // closed. `accepted` is true when the dialog is accepted, false otherwise.
