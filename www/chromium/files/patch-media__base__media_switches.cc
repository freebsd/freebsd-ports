--- ./media/base/media_switches.cc.orig	2010-12-16 02:11:21.000000000 +0100
+++ ./media/base/media_switches.cc	2010-12-20 20:15:08.000000000 +0100
@@ -6,7 +6,7 @@
 
 namespace switches {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // The Alsa device to use when opening an audio stream.
 const char kAlsaOutputDevice[] = "alsa-output-device";
 // The Alsa device to use when opening an audio input stream.
