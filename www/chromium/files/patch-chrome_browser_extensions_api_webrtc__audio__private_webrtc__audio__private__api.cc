--- chrome/browser/extensions/api/webrtc_audio_private/webrtc_audio_private_api.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/extensions/api/webrtc_audio_private/webrtc_audio_private_api.cc
@@ -563,7 +563,10 @@ bool WebrtcAudioPrivateSetAudioExperimentsFunction::Ru
       return false;
     }
 
+#if BUILDFLAG(ENABLE_WEBRTC)
+    // To workaround side effect of having 'enable_webrtc=false'
     host->SetEchoCanceller3(*params->audio_experiments.enable_aec3);
+#endif
   }
 
   SendResponse(true);
