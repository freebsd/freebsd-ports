--- src/3rdparty/chromium/third_party/ffmpeg/libavutil/cpu.c.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/ffmpeg/libavutil/cpu.c
@@ -38,10 +38,7 @@
 #if HAVE_GETPROCESSAFFINITYMASK || HAVE_WINRT
 #include <windows.h>
 #endif
-#if HAVE_SYSCTL
-#if HAVE_SYS_PARAM_H
-#include <sys/param.h>
-#endif
+#if HAVE_SYSCTL && !defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
