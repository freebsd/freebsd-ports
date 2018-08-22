--- Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp.orig	2018-07-17 16:48:21 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp
@@ -24,7 +24,7 @@
 #include "../os/windows/AudioInputWave.h"
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #endif
@@ -63,7 +63,7 @@ AudioInput::AudioInput(std::string devic
 		return new AudioInputWave(deviceID);
 #endif
 	return new AudioInputWASAPI(deviceID);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	if(AudioInputPulse::IsAvailable()){
 		AudioInputPulse* aip=new AudioInputPulse(deviceID);
 		if(!aip->IsInitialized())
@@ -96,7 +96,7 @@ void AudioInput::EnumerateDevices(std::v
 	}
 #endif
 	AudioInputWASAPI::EnumerateDevices(devs);
-#elif defined(__linux__) && !defined(__ANDROID__)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 #if !defined(WITHOUT_PULSE) && !defined(WITHOUT_ALSA)
 	if(!AudioInputPulse::EnumerateDevices(devs))
 		AudioInputALSA::EnumerateDevices(devs);
