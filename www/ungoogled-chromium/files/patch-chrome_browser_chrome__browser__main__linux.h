--- chrome/browser/chrome_browser_main_linux.h.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/chrome_browser_main_linux.h
@@ -31,7 +31,7 @@ class ChromeBrowserMainPartsLinux : public ChromeBrows
 
   // ChromeBrowserMainPartsPosix overrides.
   void PostCreateMainMessageLoop() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void PostMainMessageLoopRun() override;
 #endif
   void PreProfileInit() override;
