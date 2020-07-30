--- third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2020-07-13 10:02:28 UTC
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -132,7 +132,7 @@ class AudioWorkletThreadTest : public PageTestBase {
     ASSERT_TRUE(thread->IsCurrentThread());
 // TODO(crbug.com/1022888): The worklet thread priority is always NORMAL on
 // linux.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     EXPECT_EQ(base::PlatformThread::GetCurrentThreadPriority(),
               base::ThreadPriority::NORMAL);
 #else
