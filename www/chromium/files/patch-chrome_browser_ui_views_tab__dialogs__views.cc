--- chrome/browser/ui/views/tab_dialogs_views.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/ui/views/tab_dialogs_views.cc
@@ -15,7 +15,7 @@
 #include "content/public/browser/web_contents.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/web_apps/deprecated_apps_dialog_view.h"
 #endif
 
@@ -83,7 +83,7 @@ void TabDialogsViews::ShowDeprecatedAppsDialog(
     const std::set<extensions::ExtensionId>& deprecated_app_ids,
     content::WebContents* web_contents) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   DeprecatedAppsDialogView::CreateAndShowDialog(deprecated_app_ids,
                                                 web_contents);
 #endif
