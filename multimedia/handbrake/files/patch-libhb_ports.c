--- libhb/ports.c.orig	2019-11-09 20:44:32 UTC
+++ libhb/ports.c
@@ -28,7 +28,11 @@
 #if defined(SYS_DARWIN) || defined(SYS_FREEBSD)
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#if HB_PROJECT_FEATURE_QSV && defined(SYS_FREEBSD)
+#include <libdrm/drm.h>
+#include <fcntl.h>
 #endif
+#endif
 
 #ifdef SYS_OPENBSD
 #include <sys/param.h>
@@ -1518,7 +1522,7 @@ char * hb_strndup(const char * src, size_t len)
 }
 
 #if HB_PROJECT_FEATURE_QSV
-#ifdef SYS_LINUX
+#if defined(SYS_LINUX) || defined(SYS_FREEBSD)
 
 #define MAX_NODES             16
 #define DRI_RENDER_NODE_START 128
@@ -1676,7 +1680,7 @@ void hb_display_close(hb_display_t ** _d)
     *_d = NULL;
 }
 
-#else // !SYS_LINUX
+#else // !SYS_LINUX && !SYS_FREEBSD
 
 hb_display_t * hb_display_init(const char         *  driver_name,
                                const char * const * interface_names)
@@ -1689,7 +1693,7 @@ void hb_display_close(hb_display_t ** _d)
     (void)_d;
 }
 
-#endif // SYS_LINUX
+#endif // SYS_LINUX || SYS_FREEBSD
 #else // !HB_PROJECT_FEATURE_QSV
 
 hb_display_t * hb_display_init(const char         *  driver_name,
