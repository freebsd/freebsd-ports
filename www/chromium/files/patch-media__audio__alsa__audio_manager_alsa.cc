--- media/audio/alsa/audio_manager_alsa.cc.orig	2016-04-07 19:01:10 UTC
+++ media/audio/alsa/audio_manager_alsa.cc
@@ -128,7 +128,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
   int card = -1;
 
   // Loop through the sound cards to get ALSA device hints.
+#ifdef OS_LINUX
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = NULL;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -140,7 +142,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#ifdef OS_LINUX
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(
@@ -226,7 +230,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvail
     // goes through software conversion if needed (e.g. incompatible
     // sample rate).
     // TODO(joi): Should we prefer "hw" instead?
+#ifdef OS_LINUX
     static const char kDeviceTypeDesired[] = "plughw";
+#else
+    static const char kDeviceTypeDesired[] = "plug";
+#endif
     return strncmp(kDeviceTypeDesired,
                    device_name,
                    arraysize(kDeviceTypeDesired) - 1) == 0;
@@ -250,7 +258,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is a access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#ifdef OS_LINUX
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       for (void** hint_iter = hints; *hint_iter != NULL; hint_iter++) {
@@ -274,7 +284,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#ifdef OS_LINUX
   }
+#endif
 
   return has_device;
 }
