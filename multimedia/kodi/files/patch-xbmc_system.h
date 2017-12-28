--- xbmc/system.h.orig	2017-11-14 16:55:01 UTC
+++ xbmc/system.h
@@ -143,7 +143,11 @@
 #endif
 #else
 #ifndef HAVE_X11
+#if defined(TARGET_LINUX)
 #define HAS_LINUX_EVENTS
+#elif defined(TARGET_FREEBSD)
+#define HAS_FREEBSD_EVENTS
+#endif
 #endif
 #endif
 #define HAS_LINUX_NETWORK
