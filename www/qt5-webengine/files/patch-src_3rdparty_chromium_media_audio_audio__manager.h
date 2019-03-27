--- src/3rdparty/chromium/media/audio/audio_manager.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/media/audio/audio_manager.h
@@ -70,7 +70,7 @@ class MEDIA_EXPORT AudioManager {
   static void StartHangMonitorIfNeeded(
       scoped_refptr<base::SingleThreadTaskRunner> task_runner);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sets the name of the audio source as seen by external apps. Only actually
   // used with PulseAudio as of this writing.
   static void SetGlobalAppName(const std::string& app_name);
