--- headless/lib/headless_content_main_delegate.cc.orig	2017-07-25 21:04:56.000000000 +0200
+++ headless/lib/headless_content_main_delegate.cc	2017-08-02 13:54:14.222324000 +0200
@@ -233,7 +233,7 @@
 }
 #endif  // !defined(CHROME_MULTIPLE_DLL_CHILD)
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void HeadlessContentMainDelegate::ZygoteForked() {
   const base::CommandLine& command_line(
       *base::CommandLine::ForCurrentProcess());
