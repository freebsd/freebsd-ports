--- chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.cc
@@ -164,7 +164,7 @@ ScheduledRestartBubbleController::GetScheduledRestartM
   if (scheduled_restart_manager_for_testing_) {
     return scheduled_restart_manager_for_testing_;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return g_browser_process && g_browser_process->GetFeatures()
              ? g_browser_process->GetFeatures()->scheduled_restart_manager()
              : nullptr;
