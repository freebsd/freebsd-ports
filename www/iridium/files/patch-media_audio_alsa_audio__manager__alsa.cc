--- media/audio/alsa/audio_manager_alsa.cc.orig	2024-11-04 08:56:03 UTC
+++ media/audio/alsa/audio_manager_alsa.cc
@@ -100,7 +100,9 @@ void AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
   int card = -1;
 
   // Loop through the physical sound cards to get ALSA device hints.
+#if !BUILDFLAG(IS_BSD) 
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = NULL;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -112,7 +114,9 @@ void AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD) 
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(AudioManagerAlsa::StreamType type,
@@ -195,7 +199,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvailable(
   // goes through software conversion if needed (e.g. incompatible
   // sample rate).
   // TODO(joi): Should we prefer "hw" instead?
+#if BUILDFLAG(IS_BSD)
+  static const char kDeviceTypeDesired[] = "plug";
+#else
   static const char kDeviceTypeDesired[] = "plughw";
+#endif
   return strncmp(kDeviceTypeDesired, device_name,
                  std::size(kDeviceTypeDesired) - 1) == 0;
 }
@@ -247,7 +255,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is an access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#if !BUILDFLAG(IS_BSD)
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       for (void** hint_iter = hints; *hint_iter != NULL; hint_iter++) {
@@ -271,7 +281,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
   return has_device;
 }
