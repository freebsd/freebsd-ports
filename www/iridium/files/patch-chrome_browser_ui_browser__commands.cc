--- chrome/browser/ui/browser_commands.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/ui/browser_commands.cc
@@ -2861,7 +2861,7 @@ void OpenUpdateChromeDialog(BrowserWindowInterface* br
     ShowOutdatedUpgradeBubble(browser, browser,
                               /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
