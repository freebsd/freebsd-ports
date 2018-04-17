--- Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp.orig	2017-12-27 18:47:58 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp
@@ -19,7 +19,7 @@
 #include "../os/windows/AudioInputWave.h"
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "../os/linux/AudioInputALSA.h"
 #include "../os/linux/AudioInputPulse.h"
 #else
@@ -54,7 +54,7 @@ AudioInput *AudioInput::Create(std::stri
 		return new AudioInputWave(deviceID);
 #endif
 	return new AudioInputWASAPI(deviceID);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	if(AudioInputPulse::IsAvailable()){
 		AudioInputPulse* aip=new AudioInputPulse(deviceID);
 		if(!aip->IsInitialized())
@@ -87,7 +87,7 @@ void AudioInput::EnumerateDevices(std::v
 	}
 #endif
 	AudioInputWASAPI::EnumerateDevices(devs);
-#elif defined(__linux__) && !defined(__ANDROID__)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 	if(!AudioInputPulse::IsAvailable() || !AudioInputPulse::EnumerateDevices(devs))
 		AudioInputALSA::EnumerateDevices(devs);
 #endif
