--- third_party/blink/renderer/modules/media/audio/audio_device_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ third_party/blink/renderer/modules/media/audio/audio_device_factory.cc
@@ -34,7 +34,7 @@ AudioDeviceFactory* AudioDeviceFactory::factory_ = nul
 namespace {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
 // In this case we will time out, to avoid renderer hang forever waiting for
