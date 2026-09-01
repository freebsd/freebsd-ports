--- chrome/browser/ui/browser_actions.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/browser_actions.cc
@@ -243,7 +243,7 @@
 #include "chrome/browser/ui/views/download/bubble/download_toolbar_ui_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -2610,7 +2610,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
           .Build());
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -2742,7 +2742,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
           .SetActionId(kActionExit)
           .Build());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -3782,7 +3782,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
               [](BrowserWindowInterface* bwi, actions::ActionItem* item,
                  actions::ActionInvocationContext context) {
                 base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                 chrome::CreateDesktopShortcutForActiveWebContents(
                     bwi->GetBrowserForMigrationOnly());
 #else
@@ -4653,7 +4653,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
 #endif
 
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
