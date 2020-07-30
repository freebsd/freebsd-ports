--- headless/lib/headless_content_main_delegate.h.orig	2020-07-07 21:57:38 UTC
+++ headless/lib/headless_content_main_delegate.h
@@ -57,7 +57,7 @@ class HEADLESS_EXPORT HeadlessContentMainDelegate
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
