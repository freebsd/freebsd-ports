--- libobs-opengl/gl-egl-common.c.orig	2025-07-14 17:07:11 UTC
+++ libobs-opengl/gl-egl-common.c
@@ -33,7 +33,10 @@ typedef unsigned int drm_handle_t;
 
 #else
 
+#include <fcntl.h>
+#include <unistd.h>
 #include <stdint.h>
+#include <xf86drm.h>
 #include <sys/ioccom.h>
 #include <sys/types.h>
 typedef int8_t __s8;
