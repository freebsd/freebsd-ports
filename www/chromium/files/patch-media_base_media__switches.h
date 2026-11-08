--- media/base/media_switches.h.orig	2026-10-18 13:29:39 UTC
+++ media/base/media_switches.h
@@ -449,7 +449,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kIgnoreUiGains);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kShowForceRespectUiGainsToggle);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kReduceHardwareVideoDecoderBuffers);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoEncoding);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2H264TemporalLayerHWEncoding);
@@ -460,7 +460,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kFuchsiaCdmStoragePa
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kFuchsiaMediacodecVideoEncoder);
 #endif  // BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinux);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinuxGL);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoEncodeLinux);
@@ -471,6 +471,18 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreferV4L2VideoAcce
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForCast);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForScreenShare);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiIgnoreDriverChecks);
+
+enum class AudioBackend {
+  kAuto,
+  kPulseAudio,
+  kSndio,
+  kAlsa
+};
+
+MEDIA_EXPORT BASE_DECLARE_FEATURE(kAudioBackend);
+MEDIA_EXPORT extern const base::FeatureParam<
+    AudioBackend>
+    kAudioBackendParam;
 #endif  // BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_MAC)
