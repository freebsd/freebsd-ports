--- content/public/common/content_switches.h.orig	2016-05-11 19:02:21 UTC
+++ content/public/common/content_switches.h
@@ -284,7 +284,7 @@ CONTENT_EXPORT extern const char kDisabl
 CONTENT_EXPORT extern const char kDisableVaapiAcceleratedVideoEncode[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
