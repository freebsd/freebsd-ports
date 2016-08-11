--- server/mp4live/audio_oss_source.cpp.orig	2005-09-07 22:28:01 UTC
+++ server/mp4live/audio_oss_source.cpp
@@ -265,7 +265,7 @@ bool COSSAudioSource::InitDevice(void)
 
   rc = ioctl(m_audioDevice, SNDCTL_DSP_SPEED, &samplingRate);
 
-  if (rc < 0 || abs(samplingRate - targetSamplingRate) > 1) {
+  if (rc < 0 || abs((int)(samplingRate - targetSamplingRate) > 1)) {
     error_message("Couldn't set sampling rate for %s", deviceName);
     close(m_audioDevice);
     return false;
@@ -450,7 +450,7 @@ bool CAudioCapabilities::ProbeDevice()
     rc = ioctl(audioDevice, SNDCTL_DSP_SPEED, &samplingRate);
 
     // invalid sampling rate, allow deviation of 1 sample/sec
-    if (rc < 0 || abs(samplingRate - targetRate) > 1) {
+    if (rc < 0 || abs((int)(samplingRate - targetRate) > 1)) {
       debug_message("audio device %s doesn't support sampling rate %u",
                     m_deviceName, targetRate);
       continue;
