--- chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -59,7 +59,7 @@ bool ShouldCreateCustomLinksManager() {
 
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(ntp_tiles::kNtpEnterpriseShortcuts);
 #else
   return false;
