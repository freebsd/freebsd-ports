--- src/3rdparty/chromium/headless/lib/headless_content_main_delegate.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/headless/lib/headless_content_main_delegate.h
@@ -58,7 +58,7 @@ class HEADLESS_EXPORT HeadlessContentMainDelegate
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
