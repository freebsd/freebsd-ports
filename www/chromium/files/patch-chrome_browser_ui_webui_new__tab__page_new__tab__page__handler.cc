--- chrome/browser/ui/webui/new_tab_page/new_tab_page_handler.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/webui/new_tab_page/new_tab_page_handler.cc
@@ -61,7 +61,7 @@
 #include "chrome/browser/ui/hats/hats_service_factory.h"
 #include "chrome/browser/ui/tabs/public/tab_features.h"
 #include "chrome/browser/ui/views/new_tab_footer/footer_controller.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.h"
 #endif
 #include "chrome/browser/ui/webui/new_tab_footer/new_tab_footer_helper.h"
@@ -544,7 +544,7 @@ NewTabPageHandler::NewTabPageHandler(
   }
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scheduled_restart::ScheduledRestartBubbleController::MaybeShowNTPNudge(
       web_contents_);
 #endif
