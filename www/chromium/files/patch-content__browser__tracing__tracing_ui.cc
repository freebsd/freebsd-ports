--- content/browser/tracing/tracing_ui.cc.orig	2014-10-10 08:54:14 UTC
+++ content/browser/tracing/tracing_ui.cc
@@ -330,6 +330,8 @@
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_BSD)
+  const char product[] = "Chrome_BSD";
 #else
 #error Platform not supported.
 #endif
