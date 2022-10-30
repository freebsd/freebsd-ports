--- media/base/media_switches.h.orig	2022-10-29 17:50:56 UTC
+++ media/base/media_switches.h
@@ -202,7 +202,7 @@ MEDIA_EXPORT extern const base::Feature kUseDecoderStr
 MEDIA_EXPORT extern const base::Feature kUseFakeDeviceForMediaStream;
 MEDIA_EXPORT extern const base::Feature kUseMediaHistoryStore;
 MEDIA_EXPORT extern const base::Feature kUseR16Texture;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiVideoDecodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiVideoEncodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiIgnoreDriverChecks;
@@ -310,7 +310,7 @@ MEDIA_EXPORT extern const base::FeatureParam<
 MEDIA_EXPORT extern const base::Feature kDeprecateLowUsageCodecs;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT extern const base::Feature kUseOutOfProcessVideoDecoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
