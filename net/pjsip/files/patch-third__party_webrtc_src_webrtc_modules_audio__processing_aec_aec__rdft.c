--- third_party/webrtc/src/webrtc/modules/audio_processing/aec/aec_rdft.c.orig	2016-08-25 01:36:33 UTC
+++ third_party/webrtc/src/webrtc/modules/audio_processing/aec/aec_rdft.c
@@ -571,7 +571,7 @@ void aec_rdft_init(void) {
   cftfsub_128 = cftfsub_128_C;
   cftbsub_128 = cftbsub_128_C;
   bitrv2_128 = bitrv2_128_C;
-#if defined(WEBRTC_ARCH_X86_FAMILY)
+#if defined(WEBRTC_ARCH_X86_FAMILY) && defined(__SSE2__)
   if (WebRtc_GetCPUInfo(kSSE2)) {
     aec_rdft_init_sse2();
   }
