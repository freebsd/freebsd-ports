--- third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -44,7 +44,7 @@ constexpr base::TimeDelta kEncodeRowSlackBeforeDeadlin
 
 /* The value is based on user statistics on Nov 2017. */
 #if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-     defined(OS_WIN))
+     defined(OS_WIN)) || defined(OS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
