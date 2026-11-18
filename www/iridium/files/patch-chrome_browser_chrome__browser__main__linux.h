--- chrome/browser/chrome_browser_main_linux.h.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/chrome_browser_main_linux.h
@@ -40,7 +40,7 @@ class ChromeBrowserMainPartsLinux : public ChromeBrows
   void PreCreateMainMessageLoop() override;
 #endif
   void PostCreateMainMessageLoop() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void PostMainMessageLoopRun() override;
 #endif
   void PreProfileInit() override;
