--- eplaser/gdevescv.c.orig	Wed Jul  3 13:17:26 2002
+++ eplaser/gdevescv.c	Fri Nov 29 21:59:00 2002
@@ -37,8 +37,7 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
+#include <string.h>
 
 #include "math_.h"
 #include "gx.h"
@@ -305,30 +304,30 @@
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
@@ -585,6 +584,8 @@
     {421, 595, 15, "A5"},		/* A5 */
     {709, 1002, 24, "B4"},		/* B4 */
     {501, 709, 25, "B5"},		/* B5 */
+    {729, 1032, 24, "B5"},		/* JIS B4 */
+    {516, 729, 25, "B5"},		/* JIS B5 */
     {612, 792, 30, "LT"},		/* Letter */
     {396, 612, 31, "HLT"},		/* Half Letter */
     {612, 1008, 32, "LGL"},		/* Legal */
@@ -1849,13 +1850,13 @@
 
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
@@ -1873,7 +1874,7 @@
 
     {
 
-#if GS_VERSION_MAJOR == 6
+#if GS_VERSION_MAJOR >= 6
 	if (height == 260)
 	    height = 1;
 #endif
@@ -2011,13 +2012,13 @@
 
 
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
