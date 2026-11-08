--- chrome/browser/ui/browser_commands.cc.orig	2026-10-22 09:04:01 UTC
+++ chrome/browser/ui/browser_commands.cc
@@ -1422,7 +1422,7 @@ void NewTabToRight(BrowserWindowInterface* browser) {
 }
 
 void NewTabFromClipboardURL(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::Clipboard::IsSupportedClipboardBuffer(
           ui::ClipboardBuffer::kSelection)) {
     ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
@@ -2797,7 +2797,7 @@ void OpenUpdateChromeDialog(BrowserWindowInterface* br
     ShowOutdatedUpgradeBubble(browser, browser,
                               /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
