--- media/base/media_switches.h.orig	2021-12-31 00:57:35 UTC
+++ media/base/media_switches.h
@@ -190,10 +190,10 @@ MEDIA_EXPORT extern const base::Feature kUseFakeDevice
 MEDIA_EXPORT extern const base::Feature kUseMediaHistoryStore;
 MEDIA_EXPORT extern const base::Feature kUseR16Texture;
 MEDIA_EXPORT extern const base::Feature kUseSodaForLiveCaption;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiVideoDecodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiVideoEncodeLinux;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiAV1Decoder;
 MEDIA_EXPORT extern const base::Feature kVaapiLowPowerEncoderGen9x;
 MEDIA_EXPORT extern const base::Feature kVaapiEnforceVideoMinMaxResolution;
