--- chrome/browser/ui/tabs/tab_features.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -88,7 +88,7 @@
 #include "chrome/browser/ui/webui/webui_embedding_context.h"
 #include "components/contextual_tasks/public/features.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/wallet/chrome_walletable_pass_client.h"
 #endif
 #include "chrome/browser/ui/contextual_search/tab_contextualization_controller.h"
@@ -442,7 +442,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 
