--- chrome/browser/ui/webui/search_engine_choice/search_engine_choice_ui.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/ui/webui/search_engine_choice/search_engine_choice_ui.cc
@@ -136,7 +136,7 @@ SearchEngineChoiceUI::SearchEngineChoiceUI(content::We
       search_engine_choice_service->IsDsePropagationAllowedForGuest());
 
   const bool is_first_run_desktop_refresh_enabled =
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       switches::IsFirstRunDesktopRefreshEnabled(
           CHECK_DEREF(regional_capabilities_service)
               .IsInSearchEngineChoiceScreenRegion());
