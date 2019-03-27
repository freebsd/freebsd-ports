--- src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -34,7 +34,7 @@ namespace {
 constexpr TimeDelta kSlackBeforeDeadline = TimeDelta::FromMilliseconds(1);
 
 /* The value is based on user statistics on Nov 2017. */
-#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN))
+#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)) || defined(OS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
