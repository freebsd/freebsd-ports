--- third_party/WebKit/Source/core/html/canvas/CanvasAsyncBlobCreator.cpp.orig	2018-03-03 21:15:48.546036000 +0100
+++ third_party/WebKit/Source/core/html/canvas/CanvasAsyncBlobCreator.cpp	2018-03-03 21:16:22.040188000 +0100
@@ -31,7 +31,7 @@
     0.001;  // a small slack period between deadline and current time for safety
 
 /* The value is based on user statistics on Nov 2017. */
-#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN))
+#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD))
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
