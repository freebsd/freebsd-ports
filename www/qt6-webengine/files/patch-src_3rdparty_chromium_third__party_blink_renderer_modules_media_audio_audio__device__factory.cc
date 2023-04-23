--- src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/audio_device_factory.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/audio_device_factory.cc
@@ -35,7 +35,7 @@ AudioDeviceFactory* g_factory_override = nullptr;
 AudioDeviceFactory* g_factory_override = nullptr;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
 // In this case we will time out, to avoid renderer hang forever waiting for
