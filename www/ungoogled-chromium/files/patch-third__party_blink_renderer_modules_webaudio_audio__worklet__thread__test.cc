--- third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2026-05-09 18:09:27 UTC
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -466,7 +466,7 @@ class AudioWorkletThreadPriorityTest
     // acquire SCHED_RR, so the thread remains in SCHED_NORMAL. However,
     // ChromeOS applies specific optimizations (Nice -10 and uclamp boost)
     // that are not present on standard Linux.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (expected_priority == base::ThreadType::kRealtimeAudio ||
         expected_priority == base::ThreadType::kPresentation) {
       EXPECT_EQ(actual_priority, base::ThreadType::kDefault);
