--- eplaser/gdevesmv.c.orig	Fri Jan 24 13:34:55 2003
+++ eplaser/gdevesmv.c	Tue Mar 25 18:13:37 2003
@@ -34,8 +34,6 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
 #include <string.h>
 
 #include "math_.h"
@@ -393,30 +391,30 @@
 
 
 /* Vector device implementation */
-private int esmv_beginpage(P1(gx_device_vector * vdev));
-private int esmv_setfillcolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
-private int esmv_setstrokecolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
-private int esmv_setdash(P4(gx_device_vector * vdev, const float *pattern, 
-			      uint count, floatp offset));
-private int esmv_setflat(P2(gx_device_vector * vdev, floatp flatness));
-private int esmv_setlogop(P3(gx_device_vector * vdev, gs_logical_operation_t lop, 
-			       gs_logical_operation_t diff));
+private int esmv_beginpage(gx_device_vector * vdev);
+private int esmv_setfillcolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int esmv_setstrokecolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int esmv_setdash(gx_device_vector * vdev, const float *pattern, 
+			      uint count, floatp offset);
+private int esmv_setflat(gx_device_vector * vdev, floatp flatness);
+private int esmv_setlogop(gx_device_vector * vdev, gs_logical_operation_t lop, 
+			       gs_logical_operation_t diff);
 private int esmv_vector_dorect(gx_device_vector * vdev, fixed x0, fixed y0, fixed x1,
 			       fixed y1, gx_path_type_t type);
 private int esmv_vector_dopath(gx_device_vector * vdev, const gx_path * ppath,
 			       gx_path_type_t type);
-private int esmv_beginpath(P2(gx_device_vector * vdev, gx_path_type_t type));
-private int esmv_moveto(P6(gx_device_vector * vdev, floatp x0, floatp y0,
-			   floatp x, floatp y, gx_path_type_t type));
-private int esmv_lineto(P6(gx_device_vector * vdev, floatp x0, floatp y0,
-			   floatp x, floatp y, gx_path_type_t type));
-private int esmv_curveto(P10(gx_device_vector * vdev, floatp x0, floatp y0,
+private int esmv_beginpath(gx_device_vector * vdev, gx_path_type_t type);
+private int esmv_moveto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int esmv_lineto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int esmv_curveto(gx_device_vector * vdev, floatp x0, floatp y0,
 			       floatp x1, floatp y1, floatp x2, floatp y2,
-			       floatp x3, floatp y3, gx_path_type_t type));
-private int esmv_closepath(P6(gx_device_vector * vdev, floatp x, floatp y,
-				floatp x_start, floatp y_start, gx_path_type_t type));
+			       floatp x3, floatp y3, gx_path_type_t type);
+private int esmv_closepath(gx_device_vector * vdev, floatp x, floatp y,
+				floatp x_start, floatp y_start, gx_path_type_t type);
 
-private int esmv_endpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+private int esmv_endpath(gx_device_vector * vdev, gx_path_type_t type);
 private int esmv_setlinewidth(gx_device_vector * vdev, floatp width);
 private int esmv_setlinecap(gx_device_vector * vdev, gs_line_cap cap);
 private int esmv_setlinejoin(gx_device_vector * vdev, gs_line_join join);
@@ -1958,13 +1956,13 @@
 
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
@@ -1982,7 +1980,7 @@
 
     {
 
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 	if (height == 260)
 	    height = 1;
 #endif
@@ -2139,13 +2137,13 @@
 
 
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
