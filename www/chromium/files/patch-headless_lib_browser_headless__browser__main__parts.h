--- headless/lib/browser/headless_browser_main_parts.h.orig	2020-09-21 18:39:18 UTC
+++ headless/lib/browser/headless_browser_main_parts.h
@@ -32,7 +32,7 @@ class HeadlessBrowserMainParts : public content::Brows
 #if defined(OS_MACOSX)
   void PreMainMessageLoopStart() override;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void PostMainMessageLoopStart() override;
 #endif
   void QuitMainMessageLoop();
