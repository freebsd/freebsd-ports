--- content/renderer/media/audio/audio_device_factory.cc.orig	2019-02-06 23:09:19.538251000 +0100
+++ content/renderer/media/audio/audio_device_factory.cc	2019-02-06 23:09:35.343662000 +0100
@@ -33,7 +33,7 @@
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
