--- src/Qt/AudioPlaybackThread.cpp.orig	2024-12-21 22:27:30 UTC
+++ src/Qt/AudioPlaybackThread.cpp
@@ -111,8 +111,17 @@ namespace openshot
 
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
 				deviceSetup.bufferSize = Settings::Instance()->PLAYBACK_AUDIO_BUFFER_SIZE;
 
 				// Loop through common sample rates, starting with the user's requested rate
