--- third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2026-01-16 14:21:21 UTC
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -463,7 +463,7 @@ class AudioWorkletThreadPriorityTest
 
     // TODO(crbug.com/1022888): The worklet thread priority is always NORMAL
     // on OS_LINUX and OS_CHROMEOS regardless of the thread priority setting.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (expected_priority == base::ThreadType::kRealtimeAudio ||
         expected_priority == base::ThreadType::kDisplayCritical) {
       EXPECT_EQ(actual_priority, base::ThreadType::kDefault);
