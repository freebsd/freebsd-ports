--- chrome/browser/ui/tabs/tab_features.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -80,7 +80,7 @@
 #include "chrome/browser/ui/web_applications/pwa_install_page_action.h"
 #include "chrome/browser/ui/webui/webui_embedding_context.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/wallet/chrome_walletable_pass_client.h"
 #endif
 #include "chrome/browser/web_applications/web_app_tab_helper.h"
@@ -401,7 +401,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 
