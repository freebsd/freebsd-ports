--- third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2021-12-14 11:45:12 UTC
+++ third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -43,7 +43,7 @@ constexpr base::TimeDelta kEncodeRowSlackBeforeDeadlin
     base::Microseconds(100);
 
 /* The value is based on user statistics on Nov 2017. */
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
      defined(OS_WIN))
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
