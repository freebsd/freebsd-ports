--- headless/lib/browser/headless_browser_main_parts.h.orig	2021-12-14 11:45:07 UTC
+++ headless/lib/browser/headless_browser_main_parts.h
@@ -50,7 +50,7 @@ class HEADLESS_EXPORT HeadlessBrowserMainParts
 #if defined(OS_MAC)
   void PreCreateMainMessageLoop() override;
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   void PostCreateMainMessageLoop() override;
 #endif
   void QuitMainMessageLoop();
