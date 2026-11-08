--- chrome/browser/defaults.cc.orig	2026-04-09 06:05:42 UTC
+++ chrome/browser/defaults.cc
@@ -30,7 +30,7 @@ const bool kAlwaysCreateTabbedBrowserOnSessionRestore 
 const bool kShowHelpMenuItemIcon = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
