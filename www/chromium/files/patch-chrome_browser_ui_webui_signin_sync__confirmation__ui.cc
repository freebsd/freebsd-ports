--- chrome/browser/ui/webui/signin/sync_confirmation_ui.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/webui/signin/sync_confirmation_ui.cc
@@ -180,7 +180,7 @@ SyncConfirmationUI::SyncConfirmationUI(content::WebUI*
                     IDS_SYNC_LOADING_CONFIRMATION_TITLE);
 
   bool is_first_run_desktop_refresh_enabled = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool is_in_search_engine_choice_region =
       CHECK_DEREF(regional_capabilities::RegionalCapabilitiesServiceFactory::
                       GetForProfile(profile_))
