--- chrome/browser/process_singleton.h.orig	2011-03-20 22:02:04.272739829 +0200
+++ chrome/browser/process_singleton.h	2011-03-20 22:02:04.444737667 +0200
@@ -67,7 +67,7 @@
   // instance.
   NotifyResult NotifyOtherProcessOrCreate();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Exposed for testing.  We use a timeout on Linux, and in tests we want
   // this timeout to be short.
   NotifyResult NotifyOtherProcessWithTimeout(const CommandLine& command_line,
