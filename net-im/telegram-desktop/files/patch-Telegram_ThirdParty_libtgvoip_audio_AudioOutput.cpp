--- Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp.orig	2018-07-17 16:48:21 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp
@@ -27,7 +27,7 @@
 #include "../os/windows/AudioOutputWave.h"
 #endif
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioOutputALSA.h"
 #endif
@@ -59,7 +59,7 @@ int32_t AudioOutput::estimatedDelay=60;
 		return std::unique_ptr<AudioOutput>(new AudioOutputWave(deviceID));
 #endif
 	return std::unique_ptr<AudioOutput>(new AudioOutputWASAPI(deviceID));
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	if(AudioOutputPulse::IsAvailable()){
 		AudioOutputPulse* aop=new AudioOutputPulse(deviceID);
 		if(!aop->IsInitialized())
@@ -107,7 +107,7 @@ void AudioOutput::EnumerateDevices(std::
 	}
 #endif
 	AudioOutputWASAPI::EnumerateDevices(devs);
-#elif defined(__linux__) && !defined(__ANDROID__)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 #if !defined(WITHOUT_PULSE) && !defined(WITHOUT_ALSA)
 	if(!AudioOutputPulse::EnumerateDevices(devs))
 		AudioOutputALSA::EnumerateDevices(devs);
