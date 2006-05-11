--- talk/session/phone/linphonemediaengine.cc.orig	Wed Feb 22 16:32:44 2006
+++ talk/session/phone/linphonemediaengine.cc	Wed Feb 22 16:41:45 2006
@@ -65,6 +65,7 @@
   
   pthread_attr_init(&attr);
   pthread_create(&thread_, &attr, &thread_function, this);
+  pthread_attr_destroy(&attr);
 }
 
 LinphoneMediaChannel::~LinphoneMediaChannel() {
@@ -118,8 +119,8 @@
   mute_ = !send;
 }
 
-float LinphoneMediaChannel::GetCurrentQuality() {}
-int LinphoneMediaChannel::GetOutputLevel() {}
+float LinphoneMediaChannel::GetCurrentQuality() { return 0; }
+int LinphoneMediaChannel::GetOutputLevel() { return 0; }
 
 LinphoneMediaEngine::LinphoneMediaEngine() {}
 LinphoneMediaEngine::~LinphoneMediaEngine() {}
@@ -139,7 +140,7 @@
  
 #ifdef HAVE_SPEEX
   ms_speex_codec_init();
-  rtp_profile_set_payload(&av_profile, 110, &speex_wb);
+  rtp_profile_set_payload(&av_profile, 110, &payload_type_speex_wb);
   codecs_.push_back(Codec(110, "speex", 8));
 #endif
 
@@ -149,7 +150,7 @@
   codecs_.push_back(Codec(102, "iLBC", 4));
 #endif
 
-  rtp_profile_set_payload(&av_profile, 0, &pcmu8000);
+  rtp_profile_set_payload(&av_profile, 0, &payload_type_pcmu8000);
   codecs_.push_back(Codec(0, "PCMU", 2));
   
 return true;
@@ -163,8 +164,8 @@
   return new LinphoneMediaChannel();
 }
 
-int LinphoneMediaEngine::SetAudioOptions(int options) {}
-int LinphoneMediaEngine::SetSoundDevices(int wave_in_device, int wave_out_device) {}
+int LinphoneMediaEngine::SetAudioOptions(int options) { return 0; }
+int LinphoneMediaEngine::SetSoundDevices(int wave_in_device, int wave_out_device) { return 0; }
 
-float LinphoneMediaEngine::GetCurrentQuality() {}
-int LinphoneMediaEngine::GetInputLevel() {}
+float LinphoneMediaEngine::GetCurrentQuality() { return 0; }
+int LinphoneMediaEngine::GetInputLevel() { return 0; }
