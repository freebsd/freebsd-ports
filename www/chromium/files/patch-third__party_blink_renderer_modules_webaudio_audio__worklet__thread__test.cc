--- third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2020-11-13 06:36:48 UTC
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -373,8 +373,8 @@ class AudioWorkletThreadPriorityTest
         base::PlatformThread::GetCurrentThreadPriority();
 
     // TODO(crbug.com/1022888): The worklet thread priority is always NORMAL
-    // on OS_LINUX and OS_CHROMEOS regardless of the thread priority setting.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+    // on OS_LINUX, OS_CHROMEOS and OS_BSD regardless of the thread priority setting.
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     if (expected_priority == base::ThreadPriority::REALTIME_AUDIO ||
         expected_priority == base::ThreadPriority::DISPLAY) {
       EXPECT_EQ(actual_priority, base::ThreadPriority::NORMAL);
