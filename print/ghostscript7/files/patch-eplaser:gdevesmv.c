--- eplaser/gdevesmv.c.orig	Fri Dec 14 10:50:14 2001
+++ eplaser/gdevesmv.c	Sat Apr 27 13:46:31 2002
@@ -34,8 +34,7 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
+#include <string.h>
 
 #include "math_.h"
 #include "gx.h"
@@ -1799,13 +1798,13 @@
 
 /* Process the next piece of an image. */
 private int
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 esmv_image_plane_data(gx_image_enum_common_t *info, const gx_image_plane_t *planes, int height, int *rows_used)
 #else
 esmv_image_plane_data(gx_device *dev, gx_image_enum_common_t *info, const gx_image_plane_t *planes, int height)
 #endif
 {
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
     gx_device *dev = info->dev;
 #endif
     gx_device_vector *const	vdev = (gx_device_vector *) dev;
@@ -1823,7 +1822,7 @@
 
     {
 
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 	if (height == 260)
 	    height = 1;
 #endif
@@ -1980,13 +1979,13 @@
 
 
 private int
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 esmv_image_end_image(gx_image_enum_common_t * info, bool draw_last)
 #else
 esmv_image_end_image(gx_device * dev, gx_image_enum_common_t * info, bool draw_last)
 #endif
 {
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
     gx_device *dev = info->dev;
 #endif
     gx_device_vector		*const vdev = (gx_device_vector *) dev;
