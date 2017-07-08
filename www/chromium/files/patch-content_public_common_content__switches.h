--- content/public/common/content_switches.h.orig	2017-06-05 19:03:07 UTC
+++ content/public/common/content_switches.h
@@ -294,7 +294,7 @@ CONTENT_EXPORT extern const char kDisablePanelFitting[
 CONTENT_EXPORT extern const char kDisableVaapiAcceleratedVideoEncode[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
