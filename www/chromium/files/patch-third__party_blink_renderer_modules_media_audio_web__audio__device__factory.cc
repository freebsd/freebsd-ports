--- third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc.orig	2020-11-16 14:54:17 UTC
+++ third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc
@@ -33,7 +33,7 @@ WebAudioDeviceFactory* WebAudioDeviceFactory::factory_
 namespace {
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
 // In this case we will time out, to avoid renderer hang forever waiting for
