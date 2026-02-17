--- chrome/browser/ui/tabs/tab_features.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -88,7 +88,7 @@
 #include "chrome/browser/ui/webui/webui_embedding_context.h"
 #include "components/contextual_tasks/public/features.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_tasks/contextual_tasks_tab_visit_tracker.h"
 #include "chrome/browser/wallet/chrome_walletable_pass_client.h"
 #endif
@@ -442,7 +442,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 
