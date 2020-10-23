--- content/public/common/content_switches.h.orig	2020-09-08 19:14:05 UTC
+++ content/public/common/content_switches.h
@@ -267,7 +267,7 @@ CONTENT_EXPORT extern const char kRemoteDebuggingSocke
 CONTENT_EXPORT extern const char kRendererWaitForJavaDebugger[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
