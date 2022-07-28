--- chrome/browser/ui/startup/startup_browser_creator_impl.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/ui/startup/startup_browser_creator_impl.cc
@@ -241,7 +241,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
     // at the state of the MessageLoop.
     Browser::CreateParams params = Browser::CreateParams(profile_, false);
     params.creation_source = Browser::CreationSource::kStartupCreator;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.startup_id = command_line_.GetSwitchValueASCII("desktop-startup-id");
 #endif
     browser = Browser::Create(params);
