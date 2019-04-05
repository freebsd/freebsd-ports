--- src/3rdparty/chromium/content/public/common/content_switches.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/public/common/content_switches.h
@@ -277,7 +277,7 @@ CONTENT_EXPORT extern const char kEnableOSKOverscroll[
 CONTENT_EXPORT extern const char kDisablePanelFitting[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
