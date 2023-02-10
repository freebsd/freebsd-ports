--- src/3rdparty/chromium/media/base/media_switches.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/base/media_switches.h
@@ -195,7 +195,7 @@ MEDIA_EXPORT extern const base::Feature kUseR16Texture
 MEDIA_EXPORT extern const base::Feature kUseFakeDeviceForMediaStream;
 MEDIA_EXPORT extern const base::Feature kUseMediaHistoryStore;
 MEDIA_EXPORT extern const base::Feature kUseR16Texture;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiVideoDecodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiVideoEncodeLinux;
 #endif  // BUILDFLAG(IS_LINUX)
@@ -278,7 +278,7 @@ MEDIA_EXPORT extern const base::Feature kDeprecateLowU
 MEDIA_EXPORT extern const base::Feature kDeprecateLowUsageCodecs;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT extern const base::Feature kUseOutOfProcessVideoDecoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
