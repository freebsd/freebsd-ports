--- media/base/media_switches.h.orig	2021-04-22 08:21:12 UTC
+++ media/base/media_switches.h
@@ -183,10 +183,10 @@ MEDIA_EXPORT extern const base::Feature kUseR16Texture
 MEDIA_EXPORT extern const base::Feature kUseSodaForLiveCaption;
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiVideoDecodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiVideoEncodeLinux;
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiAV1Decoder;
 MEDIA_EXPORT extern const base::Feature kVaapiLowPowerEncoderGen9x;
 MEDIA_EXPORT extern const base::Feature kVaapiEnforceVideoMinMaxResolution;
