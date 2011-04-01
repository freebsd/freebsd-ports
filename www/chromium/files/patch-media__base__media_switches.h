--- ./media/base/media_switches.h.orig	2010-12-16 02:11:21.000000000 +0100
+++ ./media/base/media_switches.h	2010-12-20 20:15:08.000000000 +0100
@@ -11,7 +11,7 @@
 
 namespace switches {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 extern const char kAlsaOutputDevice[];
 extern const char kAlsaInputDevice[];
 #endif
