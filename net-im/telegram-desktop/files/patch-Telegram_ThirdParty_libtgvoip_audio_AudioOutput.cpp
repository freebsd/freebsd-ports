--- Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp.orig	2017-12-27 18:47:58 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp
@@ -20,7 +20,7 @@
 #include "../os/windows/AudioOutputWave.h"
 #endif
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "../os/linux/AudioOutputALSA.h"
 #include "../os/linux/AudioOutputPulse.h"
 #else
@@ -52,7 +52,7 @@ AudioOutput *AudioOutput::Create(std::st
 		return new AudioOutputWave(deviceID);
 #endif
 	return new AudioOutputWASAPI(deviceID);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	if(AudioOutputPulse::IsAvailable()){
 		AudioOutputPulse* aop=new AudioOutputPulse(deviceID);
 		if(!aop->IsInitialized())
@@ -101,7 +101,7 @@ void AudioOutput::EnumerateDevices(std::
 	}
 #endif
 	AudioOutputWASAPI::EnumerateDevices(devs);
-#elif defined(__linux__) && !defined(__ANDROID__)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 	if(!AudioOutputPulse::IsAvailable() || !AudioOutputPulse::EnumerateDevices(devs))
 		AudioOutputALSA::EnumerateDevices(devs);
 #endif
