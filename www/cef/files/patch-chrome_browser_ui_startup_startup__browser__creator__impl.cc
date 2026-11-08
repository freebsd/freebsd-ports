--- chrome/browser/ui/startup/startup_browser_creator_impl.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/startup/startup_browser_creator_impl.cc
@@ -68,7 +68,7 @@
 #include "content/public/common/content_switches.h"
 #include "url/origin.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/display/screen.h"
 #endif
@@ -91,7 +91,7 @@
 #include "chrome/browser/ui/browser_window/public/profile_browser_collection.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/search_integrity/search_integrity.h"
 #include "chrome/browser/search_integrity/search_integrity_factory.h"
 #include "chrome/browser/ui/webui/whats_new/whats_new_fetcher.h"
@@ -164,7 +164,7 @@ Browser* GetExistingBrowserForOpenBehavior(
       BrowserCollection::Order::kActivation);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool match_original_profiles =
       process_startup == chrome::startup::IsProcessStartup::kYes;
   display::Screen* const screen = display::Screen::Get();
@@ -252,7 +252,7 @@ void StartupBrowserCreatorImpl::Launch(
   DCHECK(profile);
   profile_ = profile;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check for DSE integrity if flag is enabled.
   if (base::FeatureList::IsEnabled(features::kDseIntegrity)) {
     if (auto* search_integrity_service =
@@ -306,7 +306,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
     profile_ = browser->GetProfile();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string startup_id =
       command_line_->GetSwitchValueASCII(base::nix::kXdgActivationTokenSwitch);
   if (startup_id.empty()) {
@@ -332,7 +332,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
     // at the state of the MessageLoop.
     Browser::CreateParams params = Browser::CreateParams(profile_, false);
     params.creation_source = Browser::CreationSource::kStartupCreator;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.startup_id = startup_id;
 #endif
     if (command_line_->HasSwitch(switches::kWindowName)) {
@@ -366,7 +366,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
       continue;
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Start the What's New fetch but don't add the tab at this point. The tab
     // will open as the foreground tab only if the remote content can be
     // retrieved successfully. This prevents needing to automatically close the
@@ -457,7 +457,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!create_new_browser && !startup_id.empty()) {
     base::nix::SetActivationToken(startup_id);
   }
