--- xbmc/system.h.orig       2015-08-16 16:37:32 UTC
+++ xbmc/system.h
@@ -166,7 +166,11 @@
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
