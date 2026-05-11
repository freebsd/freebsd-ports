--- chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -48,7 +48,7 @@ bool ShouldCreateCustomLinksManager() {
 
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
