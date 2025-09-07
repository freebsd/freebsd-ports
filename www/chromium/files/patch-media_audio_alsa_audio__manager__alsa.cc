--- media/audio/alsa/audio_manager_alsa.cc.orig	2025-09-06 10:01:20 UTC
+++ media/audio/alsa/audio_manager_alsa.cc
@@ -103,7 +103,9 @@ void AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
   int card = -1;
 
   // Loop through the physical sound cards to get ALSA device hints.
+#if !BUILDFLAG(IS_BSD) 
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = nullptr;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -115,7 +117,9 @@ void AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD) 
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(AudioManagerAlsa::StreamType type,
@@ -199,7 +203,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvailable(AudioMana
   // goes through software conversion if needed (e.g. incompatible
   // sample rate).
   // TODO(joi): Should we prefer "hw" instead?
+#if BUILDFLAG(IS_BSD)
+  static constexpr std::string_view kDeviceTypeDesired = "plug";
+#else
   static constexpr std::string_view kDeviceTypeDesired = "plughw";
+#endif
   return device_name.starts_with(kDeviceTypeDesired);
 }
 
@@ -250,7 +258,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is an access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#if !BUILDFLAG(IS_BSD)
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       const std::string_view unwanted_type =
@@ -279,7 +289,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
   return has_device;
 }
