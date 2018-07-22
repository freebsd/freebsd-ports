--- third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2018-07-19 19:17:49.426163000 +0200
+++ third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc	2018-07-19 19:19:17.512247000 +0200
@@ -31,7 +31,7 @@
     0.001;  // a small slack period between deadline and current time for safety
 
 /* The value is based on user statistics on Nov 2017. */
-#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN))
+#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)) || defined(OS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
