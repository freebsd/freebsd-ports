--- chrome/browser/ui/browser_commands.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/ui/browser_commands.cc
@@ -2434,7 +2434,7 @@ void OpenUpdateChromeDialog(BrowserWindowInterface* br
     ShowOutdatedUpgradeBubble(browser, browser,
                               /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
