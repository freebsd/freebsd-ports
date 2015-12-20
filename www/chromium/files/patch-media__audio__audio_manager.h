--- media/audio/audio_manager.h.orig	2015-12-05 22:20:38.929937000 +0100
+++ media/audio/audio_manager.h	2015-12-05 22:21:06.651164000 +0100
@@ -61,7 +61,7 @@
   // called previously to start the hang monitor.  Does nothing on OSX.
   static void EnableHangMonitor();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Sets the name of the audio source as seen by external apps. Only actually
   // used with PulseAudio as of this writing.
   static void SetGlobalAppName(const std::string& app_name);
