--- content/renderer/media/audio/audio_device_factory.cc.orig	2019-04-30 22:22:47 UTC
+++ content/renderer/media/audio/audio_device_factory.cc
@@ -34,7 +34,7 @@ AudioDeviceFactory* AudioDeviceFactory::factory_ = nul
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
