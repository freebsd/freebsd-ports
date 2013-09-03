--- content/renderer/media/webrtc_audio_device_impl.cc.orig	2013-09-02 21:19:20.000000000 +0300
+++ content/renderer/media/webrtc_audio_device_impl.cc	2013-09-02 21:21:36.000000000 +0300
@@ -67,7 +67,7 @@
   DCHECK_LE(number_of_frames, input_buffer_size());
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
