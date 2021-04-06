--- headless/lib/browser/headless_browser_main_parts.h.orig	2021-03-12 23:57:25 UTC
+++ headless/lib/browser/headless_browser_main_parts.h
@@ -37,7 +37,7 @@ class HeadlessBrowserMainParts : public content::Brows
 #if defined(OS_MAC)
   void PreMainMessageLoopStart() override;
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   void PostMainMessageLoopStart() override;
 #endif
   void QuitMainMessageLoop();
