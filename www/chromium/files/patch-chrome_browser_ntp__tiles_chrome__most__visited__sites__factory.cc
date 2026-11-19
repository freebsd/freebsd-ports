--- chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -49,7 +49,7 @@ bool ShouldCreatePopularSites(Profile* profile) {
 }
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
