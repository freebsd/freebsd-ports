--- chrome/browser/ui/browser_actions.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/browser_actions.cc
@@ -263,7 +263,7 @@
 #include "chrome/browser/ui/views/download/bubble/download_toolbar_ui_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/util/managed_browser_utils.h"
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
@@ -2824,7 +2824,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
           .Build());
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -2982,7 +2982,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
           .SetAccelerator(GetAcceleratorForCommandId(IDC_EXIT))
           .Build());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -3939,7 +3939,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
               [](BrowserWindowInterface* bwi, actions::ActionItem* item,
                  actions::ActionInvocationContext context) {
                 base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                 chrome::CreateDesktopShortcutForActiveWebContents(bwi);
 #else
                 web_app::CreateWebAppFromCurrentWebContents(
@@ -4893,7 +4893,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
           IDS_CHROME_ENTERPRISE_RELEASE_NOTES,
           IDS_CHROME_ENTERPRISE_RELEASE_NOTES, omnibox::kChromeProductIcon,
           /*is_pinnable=*/false)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           .SetVisible(
               enterprise_util::IsBrowserManaged(profile) &&
               base::FeatureList::IsEnabled(features::kEnterpriseReleaseNotes))
@@ -4920,7 +4920,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
           .SetVisible(false)
           .Build());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Required so IDC_SCHEDULED_RESTART_DIALOG is supported when browser
   // commands are routed through actions.
   root_action_item_->AddChild(
@@ -5041,7 +5041,7 @@ void BrowserActions::InitializeToolbarAndMiscActions()
 #endif
 
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
