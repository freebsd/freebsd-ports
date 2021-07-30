--- src/modules/rtaudio/RtAudio.cpp.orig	2021-05-06 21:27:47 UTC
+++ src/modules/rtaudio/RtAudio.cpp
@@ -8696,8 +8696,10 @@ RtAudio::DeviceInfo RtApiOss :: getDeviceInfo( unsigne
     info.nativeFormats |= RTAUDIO_SINT8;
   if ( mask & AFMT_S32_LE || mask & AFMT_S32_BE )
     info.nativeFormats |= RTAUDIO_SINT32;
+#ifdef AFMT_FLOAT
   if ( mask & AFMT_FLOAT )
     info.nativeFormats |= RTAUDIO_FLOAT32;
+#endif
   if ( mask & AFMT_S24_LE || mask & AFMT_S24_BE )
     info.nativeFormats |= RTAUDIO_SINT24;
 
@@ -9024,7 +9026,7 @@ bool RtApiOss :: probeDeviceOpen( unsigned int device,
   }
 
   // Verify the sample rate setup worked.
-  if ( abs( srate - sampleRate ) > 100 ) {
+  if ( abs( long( srate - sampleRate ) ) > 100 ) {
     close( fd );
     errorStream_ << "RtApiOss::probeDeviceOpen: device (" << ainfo.name << ") does not support sample rate (" << sampleRate << ").";
     errorText_ = errorStream_.str();
