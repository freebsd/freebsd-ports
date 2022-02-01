--- base/threading/scoped_blocking_call_unittest.cc.orig	2021-12-14 11:44:55 UTC
+++ base/threading/scoped_blocking_call_unittest.cc
@@ -282,7 +282,7 @@ TEST_F(ScopedBlockingCallIOJankMonitoringTest, ManyInA
 }
 
 TEST_F(ScopedBlockingCallIOJankMonitoringTest, OverlappingMultipleWindows) {
-  constexpr auto kJankTiming =
+  auto kJankTiming =
       internal::IOJankMonitoringWindow::kMonitoringWindow * 3 +
       internal::IOJankMonitoringWindow::kIOJankInterval * 5;
 
@@ -538,7 +538,7 @@ TEST_F(ScopedBlockingCallIOJankMonitoringTest, MultiTh
 // First one starting at 10 seconds (can't start later than that or we'll trip
 // the kTimeDiscrepancyTimeout per TaskEnvironment's inability to RunUntilIdle()
 // with pending blocked tasks).
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // https://crbug.com/1071166
 #define MAYBE_MultiThreadedOverlappedWindows \
   DISABLED_MultiThreadedOverlappedWindows
