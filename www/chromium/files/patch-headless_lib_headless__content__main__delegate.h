--- headless/lib/headless_content_main_delegate.h.orig	2017-05-09 19:02:47 UTC
+++ headless/lib/headless_content_main_delegate.h
@@ -39,7 +39,7 @@ class HeadlessContentMainDelegate : publ
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
