--- src/gnomemeeting.cpp.orig	Sun Mar 13 15:18:01 2005
+++ src/gnomemeeting.cpp	Sun Mar 13 15:19:00 2005
@@ -256,20 +256,22 @@
   
   /* Detect the devices */
   video_input_devices = PVideoInputDevice::GetDriversDeviceNames (video_plugin);
- 
+
+#ifdef HAS_IXJ 
   if (PString ("Quicknet") == audio_plugin) {
 
     audio_input_devices = OpalIxJDevice::GetDeviceNames ();
     audio_output_devices = audio_input_devices;
   }
   else {
-    
+#endif    
     audio_input_devices = 
       PSoundChannel::GetDeviceNames (audio_plugin, PSoundChannel::Recorder);
     audio_output_devices = 
       PSoundChannel::GetDeviceNames (audio_plugin, PSoundChannel::Player);
+#ifdef HAS_IXJ
   }
-    
+#endif    
   
   if (audio_input_devices.GetSize () == 0) 
     audio_input_devices += PString (_("No device found"));
