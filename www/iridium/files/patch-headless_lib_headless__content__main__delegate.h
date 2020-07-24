--- headless/lib/headless_content_main_delegate.h.orig	2020-03-16 18:39:51 UTC
+++ headless/lib/headless_content_main_delegate.h
@@ -60,7 +60,7 @@ class HEADLESS_EXPORT HeadlessContentMainDelegate
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
