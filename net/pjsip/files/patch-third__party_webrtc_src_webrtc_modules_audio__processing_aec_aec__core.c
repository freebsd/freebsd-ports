--- third_party/webrtc/src/webrtc/modules/audio_processing/aec/aec_core.c.orig	2016-08-29 08:44:54 UTC
+++ third_party/webrtc/src/webrtc/modules/audio_processing/aec/aec_core.c
@@ -1478,7 +1478,7 @@ AecCore* WebRtcAec_CreateAec() {
   WebRtcAec_ComfortNoise = ComfortNoise;
   WebRtcAec_SubbandCoherence = SubbandCoherence;
 
-#if defined(WEBRTC_ARCH_X86_FAMILY)
+#if defined(WEBRTC_ARCH_X86_FAMILY) && defined(__SSE2__)
   if (WebRtc_GetCPUInfo(kSSE2)) {
     WebRtcAec_InitAec_SSE2();
   }
