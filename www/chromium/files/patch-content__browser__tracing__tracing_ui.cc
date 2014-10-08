--- content/browser/tracing/tracing_ui.cc.orig	2014-10-02 17:39:47 UTC
+++ content/browser/tracing/tracing_ui.cc
@@ -358,6 +358,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_BSD)
+  const char product[] = "Chrome_BSD";
 #else
 #error Platform not supported.
 #endif
