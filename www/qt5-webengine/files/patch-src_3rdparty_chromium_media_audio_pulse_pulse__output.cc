--- src/3rdparty/chromium/media/audio/pulse/pulse_output.cc	2016-11-07 09:46:18.000000000 -0500
+++ src/3rdparty/chromium/media/audio/pulse/pulse_output.cc
@@ -65,7 +65,7 @@
   DCHECK(thread_checker_.CalledOnValidThread());
   return pulse::CreateOutputStream(
       &pa_mainloop_, &pa_context_, &pa_stream_, params_, device_id_,
-      AudioManager::GetGlobalAppName(), &StreamNotifyCallback,
+      "qt5-webengine", &StreamNotifyCallback,
       &StreamRequestCallback, this);
 }
 
