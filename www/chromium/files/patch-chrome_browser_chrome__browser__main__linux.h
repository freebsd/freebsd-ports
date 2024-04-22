--- chrome/browser/chrome_browser_main_linux.h.orig	2024-03-22 08:19:40 UTC
+++ chrome/browser/chrome_browser_main_linux.h
@@ -30,7 +30,7 @@ class ChromeBrowserMainPartsLinux : public ChromeBrows
 
   // ChromeBrowserMainPartsPosix overrides.
   void PostCreateMainMessageLoop() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void PostMainMessageLoopRun() override;
 #endif
   void PreProfileInit() override;
