--- eplaser/gdevescv.c.orig	Fri Dec 21 15:50:22 2001
+++ eplaser/gdevescv.c	Sat Apr 27 13:45:53 2002
@@ -37,8 +37,7 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
+#include <string.h>
 
 #include "math_.h"
 #include "gx.h"
@@ -1760,13 +1759,13 @@
 
 /* Process the next piece of an image. */
 private int
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 escv_image_plane_data(gx_image_enum_common_t *info, const gx_image_plane_t *planes, int height, int *rows_used)
 #else
 escv_image_plane_data(gx_device *dev, gx_image_enum_common_t *info, const gx_image_plane_t *planes, int height)
 #endif
 {
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
     gx_device *dev = info->dev;
 #endif
     gx_device_vector *const	vdev = (gx_device_vector *) dev;
@@ -1784,7 +1783,7 @@
 
     {
 
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 	if (height == 260)
 	    height = 1;
 #endif
@@ -1922,13 +1921,13 @@
 
 
 private int
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 escv_image_end_image(gx_image_enum_common_t * info, bool draw_last)
 #else
 escv_image_end_image(gx_device *dev, gx_image_enum_common_t * info, bool draw_last)
 #endif
 {
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
     gx_device *dev = info->dev;
 #endif
     gx_device_vector		*const vdev = (gx_device_vector *) dev;
