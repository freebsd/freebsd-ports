--- chrome/browser/ui/webui/new_tab_page/new_tab_page_handler.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/webui/new_tab_page/new_tab_page_handler.cc
@@ -540,7 +540,7 @@ NewTabPageHandler::NewTabPageHandler(
       prefs::kNtpFooterVisible,
       base::BindRepeating(&NewTabPageHandler::OnFooterVisibilityUpdated,
                           base::Unretained(this)));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   local_state_pref_change_registrar_.Init(g_browser_process->local_state());
   local_state_pref_change_registrar_.Add(
       prefs::kNTPFooterManagementNoticeEnabled,
