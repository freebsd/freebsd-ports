--- eplaser/gdevesmv.c.orig	Tue Aug 26 19:45:23 2003
+++ eplaser/gdevesmv.c	Tue Sep  9 22:08:25 2003
@@ -34,8 +34,6 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
 #include <string.h>
 
 #include "math_.h"
@@ -407,6 +405,16 @@
 
 
 /* Vector device implementation */
+#if GS_VERSION_MAJOR >= 8
+private int esmv_beginpage(gx_device_vector * vdev);
+private int esmv_setfillcolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int esmv_setstrokecolor(gx_device_vector * vdev, const gx_drawing_color * pdc);
+private int esmv_setdash(gx_device_vector * vdev, const float *pattern, 
+			      uint count, floatp offset);
+private int esmv_setflat(gx_device_vector * vdev, floatp flatness);
+private int esmv_setlogop(gx_device_vector * vdev, gs_logical_operation_t lop, 
+			       gs_logical_operation_t diff);
+#else
 private int esmv_beginpage(P1(gx_device_vector * vdev));
 private int esmv_setfillcolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
 private int esmv_setstrokecolor(P2(gx_device_vector * vdev, const gx_drawing_color * pdc));
@@ -415,10 +423,25 @@
 private int esmv_setflat(P2(gx_device_vector * vdev, floatp flatness));
 private int esmv_setlogop(P3(gx_device_vector * vdev, gs_logical_operation_t lop, 
 			       gs_logical_operation_t diff));
+#endif
 private int esmv_vector_dorect(gx_device_vector * vdev, fixed x0, fixed y0, fixed x1,
 			       fixed y1, gx_path_type_t type);
 private int esmv_vector_dopath(gx_device_vector * vdev, const gx_path * ppath,
 			       gx_path_type_t type);
+#if GS_VERSION_MAJOR >= 8
+private int esmv_beginpath(gx_device_vector * vdev, gx_path_type_t type);
+private int esmv_moveto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int esmv_lineto(gx_device_vector * vdev, floatp x0, floatp y0,
+			   floatp x, floatp y, gx_path_type_t type);
+private int esmv_curveto(gx_device_vector * vdev, floatp x0, floatp y0,
+			       floatp x1, floatp y1, floatp x2, floatp y2,
+			       floatp x3, floatp y3, gx_path_type_t type);
+private int esmv_closepath(gx_device_vector * vdev, floatp x, floatp y,
+				floatp x_start, floatp y_start, gx_path_type_t type);
+
+private int esmv_endpath(gx_device_vector * vdev, gx_path_type_t type);
+#else
 private int esmv_beginpath(P2(gx_device_vector * vdev, gx_path_type_t type));
 private int esmv_moveto(P6(gx_device_vector * vdev, floatp x0, floatp y0,
 			   floatp x, floatp y, gx_path_type_t type));
@@ -431,6 +454,7 @@
 				floatp x_start, floatp y_start, gx_path_type_t type));
 
 private int esmv_endpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+#endif
 private int esmv_setlinewidth(gx_device_vector * vdev, floatp width);
 private int esmv_setlinecap(gx_device_vector * vdev, gs_line_cap cap);
 private int esmv_setlinejoin(gx_device_vector * vdev, gs_line_join join);
