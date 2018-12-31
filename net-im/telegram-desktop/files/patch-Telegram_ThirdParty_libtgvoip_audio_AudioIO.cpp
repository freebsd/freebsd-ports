--- Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp.orig	2018-11-23 01:03:16 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp
@@ -31,7 +31,7 @@
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #include "../os/linux/AudioOutputALSA.h"
@@ -66,7 +66,7 @@ AudioIO* AudioIO::Create(){
 		return new ContextlessAudioIO<AudioInputWave, AudioOutputWave>(inputDevice, outputDevice);
 #endif
 	return new ContextlessAudioIO<AudioInputWASAPI, AudioOutputWASAPI>(inputDevice, outputDevice);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #ifndef WITHOUT_ALSA
 #ifndef WITHOUT_PULSE
 	if(AudioPulse::Load()){
