--- src/3rdparty/chromium/content/renderer/media/audio/audio_device_factory.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/renderer/media/audio/audio_device_factory.cc
@@ -33,7 +33,7 @@ AudioDeviceFactory* AudioDeviceFactory::factory_ = nul
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
