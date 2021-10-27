--- media/base/media_switches.h.orig	2021-09-24 04:26:07 UTC
+++ media/base/media_switches.h
@@ -194,10 +194,10 @@ MEDIA_EXPORT extern const base::Feature kUseFakeDevice
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
