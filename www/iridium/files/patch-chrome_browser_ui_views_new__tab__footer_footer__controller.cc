--- chrome/browser/ui/views/new_tab_footer/footer_controller.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/ui/views/new_tab_footer/footer_controller.cc
@@ -44,7 +44,7 @@ NewTabFooterController::NewTabFooterController(
       base::BindRepeating(&NewTabFooterController::UpdateFooterVisibilities,
                           weak_factory_.GetWeakPtr(),
                           /*log_on_load_metric=*/false));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   local_state_pref_change_registrar_.Init(g_browser_process->local_state());
   local_state_pref_change_registrar_.Add(
       prefs::kNTPFooterManagementNoticeEnabled,
