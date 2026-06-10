--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -46,7 +46,7 @@
 #include "chrome/browser/win/installer_downloader/installer_downloader_pref_names.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"  // nogncheck
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"  // nogncheck
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_delegate.h"
@@ -76,7 +76,7 @@ void InfoBarInternalsHandler::TriggerInfoBar(InfoBarTy
 void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsCallback callback) {
   // Please keep the entries in alphabetized order base on the type.
   std::vector<InfoBarEntryPtr> infobar_list;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   infobar_list.emplace_back(InfoBarEntry::New(
       /*type=*/InfoBarType::kDefaultBrowser, /*name=*/"Default Browser",
       /*description=*/
@@ -139,7 +139,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
 bool InfoBarInternalsHandler::TriggerInfoBarInternal(InfoBarType type) {
   // Please keep the entries in alphabetized order base on the type.
   switch (type) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       BrowserWindowInterface* const bwi =
           GetLastActiveBrowserWindowInterfaceWithAnyProfile();
