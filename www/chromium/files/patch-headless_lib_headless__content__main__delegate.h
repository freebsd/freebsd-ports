--- headless/lib/headless_content_main_delegate.h.orig	2017-06-05 19:03:08 UTC
+++ headless/lib/headless_content_main_delegate.h
@@ -44,7 +44,7 @@ class HEADLESS_EXPORT HeadlessContentMainDelegate
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
