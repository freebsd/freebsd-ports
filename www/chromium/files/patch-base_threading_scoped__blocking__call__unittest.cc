--- base/threading/scoped_blocking_call_unittest.cc.orig	2020-07-13 13:43:07 UTC
+++ base/threading/scoped_blocking_call_unittest.cc
@@ -273,7 +273,7 @@ TEST_F(ScopedBlockingCallIOJankMonitoringTest, ManyInA
 }
 
 TEST_F(ScopedBlockingCallIOJankMonitoringTest, OverlappingMultipleWindows) {
-  constexpr auto kJankTiming =
+  auto kJankTiming =
       internal::IOJankMonitoringWindow::kMonitoringWindow * 3 +
       internal::IOJankMonitoringWindow::kIOJankInterval * 5;
 
