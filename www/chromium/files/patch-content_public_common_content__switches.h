--- content/public/common/content_switches.h.orig	2017-04-19 19:06:34 UTC
+++ content/public/common/content_switches.h
@@ -294,7 +294,7 @@ CONTENT_EXPORT extern const char kDisabl
 CONTENT_EXPORT extern const char kDisableVaapiAcceleratedVideoEncode[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
