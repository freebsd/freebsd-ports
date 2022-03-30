--- headless/lib/browser/headless_browser_main_parts.h.orig	2022-03-28 18:11:04 UTC
+++ headless/lib/browser/headless_browser_main_parts.h
@@ -50,7 +50,7 @@ class HEADLESS_EXPORT HeadlessBrowserMainParts
 #if BUILDFLAG(IS_MAC)
   void PreCreateMainMessageLoop() override;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void PostCreateMainMessageLoop() override;
 #endif
   void QuitMainMessageLoop();
