--- src/chrome/browser/ui/webui/search_engine_choice/search_engine_choice_ui.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/webui/search_engine_choice/search_engine_choice_ui.cc
@@ -140,7 +140,7 @@ SearchEngineChoiceUI::SearchEngineChoice
       search_engine_choice_service->IsDsePropagationAllowedForGuest());
 
   const bool is_first_run_desktop_refresh_enabled =
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       switches::IsFirstRunDesktopRefreshEnabled(
           CHECK_DEREF(regional_capabilities_service)
               .IsInSearchEngineChoiceScreenRegion());
