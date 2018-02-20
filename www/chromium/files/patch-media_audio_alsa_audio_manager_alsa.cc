--- media/audio/alsa/audio_manager_alsa.cc.orig	2017-12-15 02:04:21.000000000 +0100
+++ media/audio/alsa/audio_manager_alsa.cc	2017-12-24 16:52:36.819099000 +0100
@@ -93,7 +93,9 @@
   int card = -1;
 
   // Loop through the sound cards to get ALSA device hints.
+#ifdef OS_LINUX
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = NULL;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -105,7 +107,9 @@
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#ifdef OS_LINUX
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(AudioManagerAlsa::StreamType type,
@@ -188,7 +192,11 @@
   // goes through software conversion if needed (e.g. incompatible
   // sample rate).
   // TODO(joi): Should we prefer "hw" instead?
+#ifdef OS_LINUX
   static const char kDeviceTypeDesired[] = "plughw";
+#else
+  static const char kDeviceTypeDesired[] = "plug";
+#endif
   return strncmp(kDeviceTypeDesired, device_name,
                  arraysize(kDeviceTypeDesired) - 1) == 0;
 }
@@ -210,7 +218,9 @@
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is a access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#ifdef OS_LINUX
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       for (void** hint_iter = hints; *hint_iter != NULL; hint_iter++) {
@@ -234,7 +244,9 @@
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#ifdef OS_LINUX
   }
+#endif
 
   return has_device;
 }
