--- eplaser/gdevescv.c.orig	Fri Jan 24 13:35:28 2003
+++ eplaser/gdevescv.c	Tue Mar 25 18:03:39 2003
@@ -37,8 +37,6 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
 #include <string.h>
 
 #include "math_.h"
@@ -321,30 +319,30 @@
 };
 
 /* Vector device implementation */
-private int escv_beginpage(P1(gx_device_vector * vdev));
-private int escv_setfillcolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
-private int escv_setstrokecolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
-private int escv_setdash(P4(gx_device_vector * vdev, const float *pattern, 
-			      uint count, floatp offset));
-private int escv_setflat(P2(gx_device_vector * vdev, floatp flatness));
-private int escv_setlogop(P3(gx_device_vector * vdev, gs_logical_operation_t lop, 
-			       gs_logical_operation_t diff));
+private int escv_beginpage(gx_device_vector * vdev);
+private int escv_setfillcolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int escv_setstrokecolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int escv_setdash(gx_device_vector * vdev, const float *pattern, 
+			      uint count, floatp offset);
+private int escv_setflat(gx_device_vector * vdev, floatp flatness);
+private int escv_setlogop(gx_device_vector * vdev, gs_logical_operation_t lop, 
+			       gs_logical_operation_t diff);
 private int escv_vector_dorect(gx_device_vector * vdev, fixed x0, fixed y0, fixed x1,
 			       fixed y1, gx_path_type_t type);
 private int escv_vector_dopath(gx_device_vector * vdev, const gx_path * ppath,
 			       gx_path_type_t type);
-private int escv_beginpath(P2(gx_device_vector * vdev, gx_path_type_t type));
-private int escv_moveto(P6(gx_device_vector * vdev, floatp x0, floatp y0,
-			   floatp x, floatp y, gx_path_type_t type));
-private int escv_lineto(P6(gx_device_vector * vdev, floatp x0, floatp y0,
-			   floatp x, floatp y, gx_path_type_t type));
-private int escv_curveto(P10(gx_device_vector * vdev, floatp x0, floatp y0,
+private int escv_beginpath(gx_device_vector * vdev, gx_path_type_t type);
+private int escv_moveto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int escv_lineto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int escv_curveto(gx_device_vector * vdev, floatp x0, floatp y0,
 			       floatp x1, floatp y1, floatp x2, floatp y2,
-			       floatp x3, floatp y3, gx_path_type_t type));
-private int escv_closepath(P6(gx_device_vector * vdev, floatp x, floatp y,
-				floatp x_start, floatp y_start, gx_path_type_t type));
+			       floatp x3, floatp y3, gx_path_type_t type);
+private int escv_closepath(gx_device_vector * vdev, floatp x, floatp y,
+				floatp x_start, floatp y_start, gx_path_type_t type);
 
-private int escv_endpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+private int escv_endpath(gx_device_vector * vdev, gx_path_type_t type);
 private int escv_setlinewidth(gx_device_vector * vdev, floatp width);
 private int escv_setlinecap(gx_device_vector * vdev, gs_line_cap cap);
 private int escv_setlinejoin(gx_device_vector * vdev, gs_line_join join);
@@ -1879,13 +1877,13 @@
 
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
@@ -1903,7 +1901,7 @@
 
     {
 
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 	if (height == 260)
 	    height = 1;
 #endif
@@ -2041,13 +2039,13 @@
 
 
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
