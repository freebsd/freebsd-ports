--- src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc
@@ -33,7 +33,7 @@ namespace {
 namespace {
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
 // In this case we will time out, to avoid renderer hang forever waiting for
