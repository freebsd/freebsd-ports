--- chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.cc
@@ -193,7 +193,7 @@ ScheduledRestartBubbleController::GetScheduledRestartM
   if (scheduled_restart_manager_for_testing_) {
     return scheduled_restart_manager_for_testing_;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return g_browser_process && g_browser_process->GetFeatures()
              ? g_browser_process->GetFeatures()->scheduled_restart_manager()
              : nullptr;
