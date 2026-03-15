--- chrome/browser/ui/startup/startup_browser_creator_impl.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/startup/startup_browser_creator_impl.cc
@@ -69,7 +69,7 @@
 #include "content/public/browser/storage_partition.h"
 #include "content/public/common/content_switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #endif
 
@@ -87,7 +87,7 @@
 #include "components/app_restore/full_restore_utils.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/search_integrity/search_integrity.h"
 #include "chrome/browser/search_integrity/search_integrity_factory.h"
 #include "chrome/browser/ui/webui/whats_new/whats_new_fetcher.h"
@@ -132,7 +132,7 @@ Browser* GetExistingBrowserForOpenBehavior(
     chrome::startup::IsProcessStartup process_startup) {
   Browser* workspace_browser = chrome::FindLastActiveWithProfile(profile);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool match_original_profiles =
       process_startup == chrome::startup::IsProcessStartup::kYes;
   display::Screen* const screen = display::Screen::Get();
@@ -280,7 +280,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
     // at the state of the MessageLoop.
     Browser::CreateParams params = Browser::CreateParams(profile_, false);
     params.creation_source = Browser::CreationSource::kStartupCreator;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.startup_id =
         command_line_->GetSwitchValueASCII("desktop-startup-id");
 #endif
@@ -310,7 +310,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
       continue;
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Start the What's New fetch but don't add the tab at this point. The tab
     // will open as the foreground tab only if the remote content can be
     // retrieved successfully. This prevents needing to automatically close the
@@ -517,7 +517,7 @@ void StartupBrowserCreatorImpl::DetermineURLsAndLaunch
             : CHROME_VERSION_STRING;
     MaybeShowNonMilestoneUpdateToast(browser, current_version_string);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check for DSE integrity if flag is enabled.
   if (base::FeatureList::IsEnabled(features::kDseIntegrity)) {
     search_integrity::SearchIntegrity* search_integrity_service =
