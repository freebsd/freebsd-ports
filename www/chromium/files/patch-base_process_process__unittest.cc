--- base/process/process_unittest.cc.orig	2021-04-20 18:58:23 UTC
+++ base/process/process_unittest.cc
@@ -139,7 +139,7 @@ TEST_F(ProcessTest, CreationTimeOtherProcess) {
   // was spawned and a time recorded after it was spawned. However, since the
   // base::Time and process creation clocks don't match, tolerate some error.
   constexpr base::TimeDelta kTolerance =
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // On Linux, process creation time is relative to boot time which has a
       // 1-second resolution. Tolerate 1 second for the imprecise boot time and
       // 100 ms for the imprecise clock.
@@ -287,6 +287,7 @@ TEST_F(ProcessTest, WaitForExitOrEventWithEventSet) {
 }
 #endif  // OS_WIN
 
+#if !defined(OS_BSD)
 // Ensure that the priority of a process is restored correctly after
 // backgrounding and restoring.
 // Note: a platform may not be willing or able to lower the priority of
@@ -344,6 +345,7 @@ TEST_F(ProcessTest, SetProcessBackgroundedSelf) {
   int new_priority = process.GetPriority();
   EXPECT_EQ(old_priority, new_priority);
 }
+#endif
 
 // Consumers can use WaitForExitWithTimeout(base::TimeDelta(), nullptr) to check
 // whether the process is still running. This may not be safe because of the
