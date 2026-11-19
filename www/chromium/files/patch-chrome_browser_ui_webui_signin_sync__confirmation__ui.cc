--- chrome/browser/ui/webui/signin/sync_confirmation_ui.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/webui/signin/sync_confirmation_ui.cc
@@ -175,7 +175,7 @@ SyncConfirmationUI::SyncConfirmationUI(content::WebUI*
   source->AddResourcePaths(kResources);
 
   bool is_first_run_desktop_refresh_enabled = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool is_in_search_engine_choice_region =
       CHECK_DEREF(regional_capabilities::RegionalCapabilitiesServiceFactory::
                       GetForProfile(profile_))
