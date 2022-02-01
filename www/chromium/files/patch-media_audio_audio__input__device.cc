--- media/audio/audio_input_device.cc.orig	2021-12-14 11:45:07 UTC
+++ media/audio/audio_input_device.cc
@@ -255,7 +255,7 @@ void AudioInputDevice::OnStreamCreated(
 // here. See comments in AliveChecker and PowerObserverHelper for details and
 // todos.
   if (detect_dead_stream_ == DeadStreamDetection::kEnabled) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     const bool stop_at_first_alive_notification = true;
     const bool pause_check_during_suspend = false;
 #else
