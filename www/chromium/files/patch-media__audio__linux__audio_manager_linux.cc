--- media/audio/linux/audio_manager_linux.cc.orig	2013-02-04 04:01:12.000000000 +0200
+++ media/audio/linux/audio_manager_linux.cc	2013-02-16 01:04:00.975548702 +0200
@@ -126,22 +126,20 @@
 void AudioManagerLinux::GetAlsaAudioInputDevices(
     media::AudioDeviceNames* device_names) {
   // Constants specified by the ALSA API for device hints.
+  static const int kGetAllDevices = -1;
   static const char kPcmInterfaceName[] = "pcm";
-  int card = -1;
 
-  // Loop through the sound cards to get ALSA device hints.
-  while (!wrapper_->CardNext(&card) && card >= 0) {
-    void** hints = NULL;
-    int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
-    if (!error) {
-      GetAlsaDevicesInfo(hints, device_names);
-
-      // Destroy the hints now that we're done with it.
-      wrapper_->DeviceNameFreeHint(hints);
-    } else {
-      DLOG(WARNING) << "GetAudioInputDevices: unable to get device hints: "
-                    << wrapper_->StrError(error);
-    }
+  void** hints = NULL;
+  int error =
+      wrapper_->DeviceNameHint(kGetAllDevices, kPcmInterfaceName, &hints);
+  if (!error) {
+    GetAlsaDevicesInfo(hints, device_names);
+
+    // Destroy the hints now that we're done with it.
+    wrapper_->DeviceNameFreeHint(hints);
+  } else {
+    DLOG(WARNING) << "GetAudioInputDevices: unable to get device hints: "
+                  << wrapper_->StrError(error);
   }
 }
 
@@ -231,40 +229,47 @@
 }
 
 bool AudioManagerLinux::HasAnyAlsaAudioDevice(StreamType stream) {
+  // Constants specified by the ALSA API for device hints.
+  static const int kGetAllDevices = -1;
   static const char kPcmInterfaceName[] = "pcm";
   static const char kIoHintName[] = "IOID";
   const char* kNotWantedDevice =
       (stream == kStreamPlayback ? "Input" : "Output");
   void** hints = NULL;
   bool has_device = false;
-  int card = -1;
 
-  // Loop through the sound cards.
-  // Don't use snd_device_name_hint(-1,..) since there is a access violation
-  // inside this ALSA API with libasound.so.2.0.0.
-  while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
-    int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
-    if (!error) {
-      for (void** hint_iter = hints; *hint_iter != NULL; hint_iter++) {
-        // Only examine devices that are |stream| capable.  Valid values are
-        // "Input", "Output", and NULL which means both input and output.
-        scoped_ptr_malloc<char> io(wrapper_->DeviceNameGetHint(*hint_iter,
-                                                               kIoHintName));
-        if (io != NULL && strcmp(kNotWantedDevice, io.get()) == 0)
-          continue;  // Wrong type, skip the device.
-
-        // Found an input device.
-        has_device = true;
-        break;
-      }
+  // If checking for Input devices, only return true if there is an
+  // actual audio card. The bots have virtual audio input devices that do
+  // not actually generate samples, breaking some tests.
+  // See crbug.com/165401.
+  if (stream == kStreamCapture) {
+    int card = -1;
+    if (wrapper_->CardNext(&card) != 0 || card == -1)
+      return false;
+  }
 
-      // Destroy the hints now that we're done with it.
-      wrapper_->DeviceNameFreeHint(hints);
-      hints = NULL;
-    } else {
-      DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
-                    << wrapper_->StrError(error);
+  int error =
+      wrapper_->DeviceNameHint(kGetAllDevices, kPcmInterfaceName, &hints);
+  if (!error) {
+    for (void** hint_iter = hints; *hint_iter != NULL; hint_iter++) {
+      // Only examine devices that are |stream| capable.  Valid values are
+      // "Input", "Output", and NULL which means both input and output.
+      scoped_ptr_malloc<char> io(wrapper_->DeviceNameGetHint(*hint_iter,
+                                                             kIoHintName));
+      if (io != NULL && strcmp(kNotWantedDevice, io.get()) == 0)
+        continue;  // Wrong type, skip the device.
+
+      // Found a device of the |stream| type.
+      has_device = true;
+      break;
     }
+
+    // Destroy the hints now that we're done with it.
+    wrapper_->DeviceNameFreeHint(hints);
+    hints = NULL;
+  } else {
+    DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
+                  << wrapper_->StrError(error);
   }
 
   return has_device;
