--- media/audio/alsa/audio_manager_alsa.cc.orig	2026-07-01 17:42:29 UTC
+++ media/audio/alsa/audio_manager_alsa.cc
@@ -106,7 +106,9 @@ bool AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
   // Loop through the physical sound cards to get ALSA device hints.
   bool had_error = false;
   int card_next_result = 0;
+#if !BUILDFLAG(IS_BSD)
   while ((card_next_result = wrapper_->CardNext(&card)) == 0 && card >= 0) {
+#endif
     void** hints = nullptr;
     int hint_result = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!hint_result) {
@@ -119,7 +121,9 @@ bool AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(hint_result);
     }
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
   if (card_next_result != 0) {
     had_error = true;
@@ -211,7 +215,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvailable(AudioMana
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
 
@@ -262,7 +270,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is an access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#if !BUILDFLAG(IS_BSD)
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       const std::string_view unwanted_type =
@@ -291,7 +301,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
   return has_device;
 }
