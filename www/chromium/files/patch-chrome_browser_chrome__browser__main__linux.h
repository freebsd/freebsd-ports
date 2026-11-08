--- chrome/browser/chrome_browser_main_linux.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/chrome_browser_main_linux.h
@@ -37,7 +37,7 @@ class ChromeBrowserMainPartsLinux : public ChromeBrows
 
   // ChromeBrowserMainPartsPosix overrides.
   void PostCreateMainMessageLoop() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void PostMainMessageLoopRun() override;
 #endif
   void PreProfileInit() override;
