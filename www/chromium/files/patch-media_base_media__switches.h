--- media/base/media_switches.h.orig	2022-02-07 13:39:41 UTC
+++ media/base/media_switches.h
@@ -38,7 +38,7 @@ MEDIA_EXPORT extern const char kDisableBackgroundMedia
 MEDIA_EXPORT extern const char kReportVp9AsAnUnsupportedMimeType[];
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FREEBSD) || \
-    defined(OS_SOLARIS)
+    defined(OS_SOLARIS) || defined(OS_BSD)
 MEDIA_EXPORT extern const char kAlsaInputDevice[];
 MEDIA_EXPORT extern const char kAlsaOutputDevice[];
 #endif
@@ -187,7 +187,7 @@ MEDIA_EXPORT extern const base::Feature kUseFakeDevice
 MEDIA_EXPORT extern const base::Feature kUseMediaHistoryStore;
 MEDIA_EXPORT extern const base::Feature kUseR16Texture;
 MEDIA_EXPORT extern const base::Feature kUseSodaForLiveCaption;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiVideoDecodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiVideoEncodeLinux;
 #endif  // defined(OS_LINUX)
