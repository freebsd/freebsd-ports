--- src/Qt/AudioPlaybackThread.cpp.orig	2023-04-19 22:01:02 UTC
+++ src/Qt/AudioPlaybackThread.cpp
@@ -102,8 +102,17 @@ namespace openshot
 
 				// Settings for audio device playback
 				AudioDeviceManager::AudioDeviceSetup deviceSetup = AudioDeviceManager::AudioDeviceSetup();
-				deviceSetup.inputChannels = 0;
-				deviceSetup.outputChannels = channels;
+				deviceSetup.outputDeviceName = attempt_device.name;
+				deviceSetup.inputDeviceName = "";
+				//deviceSetup.inputChannels = 0;
+				deviceSetup.inputChannels.clear();
+				deviceSetup.useDefaultInputChannels = false;
+				//deviceSetup.outputChannels = channels;
+				deviceSetup.outputChannels.clear();
+				for (int i = 0; i < channels; ++i) {
+					deviceSetup.outputChannels.setBit(i);
+				}
+				deviceSetup.useDefaultOutputChannels = false;
 
 				// Loop through common sample rates, starting with the user's requested rate
 				// Not all sample rates are supported by audio devices, for example, many VMs
