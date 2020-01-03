--- libhb/handbrake/ports.h.orig	2019-11-09 20:44:32 UTC
+++ libhb/handbrake/ports.h
@@ -28,7 +28,7 @@
 
 #if HB_PROJECT_FEATURE_QSV
 #include "mfx/mfxstructures.h"
-#ifdef SYS_LINUX
+#if defined(SYS_LINUX) || defined(SYS_FREEBSD)
 #include <va/va_drm.h>
 #endif
 #endif
@@ -36,9 +36,9 @@
 /************************************************************************
  * HW accel display
  ***********************************************************************/
-#ifdef SYS_LINUX
+#if defined(SYS_LINUX) || defined(SYS_FREEBSD)
 extern const char* DRM_INTEL_DRIVER_NAME;
-#endif // SYS_LINUX
+#endif // SYS_LINUX || SYS_FREEBSD
 
 typedef struct
 {
@@ -46,10 +46,10 @@ typedef struct
 #if HB_PROJECT_FEATURE_QSV
     mfxHandleType   mfxType;
 
-#ifdef SYS_LINUX
+#if defined(SYS_LINUX) || defined(SYS_FREEBSD)
     int             vaFd;
     VADisplay       vaDisplay;
-#endif // SYS_LINUX
+#endif // SYS_LINUX || SYS_FREEBSD
 #endif
 } hb_display_t;
 
