--- src/chrome/browser/ui/browser_actions.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/browser_actions.cc
@@ -246,7 +246,7 @@
 #include "chrome/browser/ui/views/download/bubble/download_toolbar_ui_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -2619,7 +2619,7 @@ void BrowserActions::InitializeToolbarAn
           .Build());
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -2779,7 +2779,7 @@ void BrowserActions::InitializeToolbarAn
           .SetAccelerator(GetAcceleratorForCommandId(IDC_EXIT))
           .Build());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -3729,7 +3729,7 @@ void BrowserActions::InitializeToolbarAn
               [](BrowserWindowInterface* bwi, actions::ActionItem* item,
                  actions::ActionInvocationContext context) {
                 base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                 chrome::CreateDesktopShortcutForActiveWebContents(bwi);
 #else
                 web_app::CreateWebAppFromCurrentWebContents(
@@ -4667,7 +4667,7 @@ void BrowserActions::InitializeToolbarAn
 #endif
 
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
