--- Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp.orig	2018-07-17 16:48:21 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp
@@ -29,7 +29,7 @@
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #include "../os/linux/AudioOutputALSA.h"
@@ -62,7 +62,7 @@ shared_ptr<AudioIO> AudioIO::Create(){
 		return std::make_shared<ContextlessAudioIO<AudioInputWave, AudioOutputWave>>(inputDevice, outputDevice);
 #endif
 	return std::make_shared<ContextlessAudioIO<AudioInputWASAPI, AudioOutputWASAPI>>(inputDevice, outputDevice);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #ifndef WITHOUT_ALSA
 #ifndef WITHOUT_PULSE
 	if(AudioPulse::Load()){
