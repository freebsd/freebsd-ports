--- chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -56,7 +56,7 @@ bool ShouldCreateCustomLinksManager() {
 
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(ntp_tiles::kNtpEnterpriseShortcuts);
 #else
   return false;
