--- chrome/browser/ui/tabs/tab_strip_prefs.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/tabs/tab_strip_prefs.cc
@@ -21,7 +21,7 @@ namespace tabs {
 
 bool GetDefaultTabSearchRightAligned() {
   // These platforms are all left aligned, the others should be right.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
