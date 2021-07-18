--- remoting/codec/webrtc_video_encoder_vpx.cc.orig	2021-04-14 18:41:07 UTC
+++ remoting/codec/webrtc_video_encoder_vpx.cc
@@ -85,11 +85,11 @@ void SetVp8CodecParameters(vpx_codec_enc_cfg_t* config
                            const webrtc::DesktopSize& size) {
   SetCommonCodecParameters(config, size);
 
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   // On Linux, using too many threads for VP8 encoding has been linked to high
   // CPU usage on machines that are under stress. See http://crbug.com/1151148.
   config->g_threads = std::min(config->g_threads, 2U);
-#endif  // defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 
   // Value of 2 means using the real time profile. This is basically a
   // redundant option since we explicitly select real time mode when doing
