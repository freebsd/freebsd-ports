--- eplaser/gdevescv.c.orig	Fri Jul 25 20:59:58 2003
+++ eplaser/gdevescv.c	Tue Sep  9 22:03:50 2003
@@ -37,8 +37,6 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
 #include <string.h>
 
 #include "math_.h"
@@ -321,6 +319,16 @@
 };
 
 /* Vector device implementation */
+#if GS_VERSION_MAJOR >= 8
+private int escv_beginpage(gx_device_vector * vdev);
+private int escv_setfillcolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int escv_setstrokecolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int escv_setdash(gx_device_vector * vdev, const float *pattern, 
+			      uint count, floatp offset);
+private int escv_setflat(gx_device_vector * vdev, floatp flatness);
+private int escv_setlogop(gx_device_vector * vdev, gs_logical_operation_t lop, 
+			       gs_logical_operation_t diff);
+#else
 private int escv_beginpage(P1(gx_device_vector * vdev));
 private int escv_setfillcolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
 private int escv_setstrokecolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
@@ -329,10 +337,25 @@
 private int escv_setflat(P2(gx_device_vector * vdev, floatp flatness));
 private int escv_setlogop(P3(gx_device_vector * vdev, gs_logical_operation_t lop, 
 			       gs_logical_operation_t diff));
+#endif
 private int escv_vector_dorect(gx_device_vector * vdev, fixed x0, fixed y0, fixed x1,
 			       fixed y1, gx_path_type_t type);
 private int escv_vector_dopath(gx_device_vector * vdev, const gx_path * ppath,
 			       gx_path_type_t type);
+#if GS_VERSION_MAJOR >= 8
+private int escv_beginpath(gx_device_vector * vdev, gx_path_type_t type);
+private int escv_moveto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int escv_lineto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int escv_curveto(gx_device_vector * vdev, floatp x0, floatp y0,
+			       floatp x1, floatp y1, floatp x2, floatp y2,
+			       floatp x3, floatp y3, gx_path_type_t type);
+private int escv_closepath(gx_device_vector * vdev, floatp x, floatp y,
+				floatp x_start, floatp y_start, gx_path_type_t type);
+
+private int escv_endpath(gx_device_vector * vdev, gx_path_type_t type);
+#else
 private int escv_beginpath(P2(gx_device_vector * vdev, gx_path_type_t type));
 private int escv_moveto(P6(gx_device_vector * vdev, floatp x0, floatp y0,
 			   floatp x, floatp y, gx_path_type_t type));
@@ -345,6 +368,7 @@
 				floatp x_start, floatp y_start, gx_path_type_t type));
 
 private int escv_endpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+#endif
 private int escv_setlinewidth(gx_device_vector * vdev, floatp width);
 private int escv_setlinecap(gx_device_vector * vdev, gs_line_cap cap);
 private int escv_setlinejoin(gx_device_vector * vdev, gs_line_join join);
