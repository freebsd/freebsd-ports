--- media/audio/audio_manager.h.orig	2017-12-15 02:04:21.000000000 +0100
+++ media/audio/audio_manager.h	2017-12-24 17:11:05.999543000 +0100
@@ -68,7 +68,7 @@
   static void StartHangMonitorIfNeeded(
       scoped_refptr<base::SingleThreadTaskRunner> task_runner);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sets the name of the audio source as seen by external apps. Only actually
   // used with PulseAudio as of this writing.
   static void SetGlobalAppName(const std::string& app_name);
