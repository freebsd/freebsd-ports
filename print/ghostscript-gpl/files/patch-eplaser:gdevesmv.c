--- eplaser/gdevesmv.c.orig	Mon May 17 14:25:19 2004
+++ eplaser/gdevesmv.c	Mon Aug  2 14:05:21 2004
@@ -34,10 +34,6 @@
 
  */
 
-#include <stdlib.h>
-#include <unistd.h>
-#include <string.h>
-
 #include "math_.h"
 #include "gx.h"
 #include "gserrors.h"
@@ -59,6 +55,10 @@
 #include "gspath.h"
 #include "gzpath.h"
 
+#include <stdlib.h>
+#include <unistd.h>
+#include <string.h>
+
 /* ---------------- Device definition ---------------- */
 
 /* Device procedures */
@@ -428,6 +428,16 @@
 
 
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
@@ -436,10 +446,25 @@
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
@@ -452,6 +477,7 @@
 				floatp x_start, floatp y_start, gx_path_type_t type));
 
 private int esmv_endpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+#endif
 private int esmv_setlinewidth(gx_device_vector * vdev, floatp width);
 private int esmv_setlinecap(gx_device_vector * vdev, gs_line_cap cap);
 private int esmv_setlinejoin(gx_device_vector * vdev, gs_line_join join);
@@ -1688,7 +1714,7 @@
             pdev->MaskState = 1;
         }
 	color_set_pure(&color, one);
-	code = gdev_vector_update_fill_color((gx_device_vector *) pdev, &color);
+	code = gdev_vector_update_fill_color((gx_device_vector *) pdev, NULL, &color);
 
 	/* ここを通過したら以下の色設定は無意味？ */
     }
@@ -1771,7 +1797,7 @@
 		 gs_logical_operation_t lop, const gx_clip_path * pcpath)
 {
     gx_device_vector const	*vdev = (gx_device_vector *) dev;
-    gx_device_esmv const	*pdev = (gx_device_esmv *) dev;
+    gx_device_esmv		*pdev = (gx_device_esmv *) dev;
     stream			*s = gdev_vector_stream(vdev);
     gx_color_index		color = gx_dc_pure_color(pdcolor);
     char			obuf[64];
@@ -1779,7 +1805,7 @@
     if (w <= 0 || h <= 0) return 0;
     
     if (depth > 1 ||
-	gdev_vector_update_fill_color(vdev, pdcolor) < 0 ||
+	gdev_vector_update_fill_color(vdev, NULL, pdcolor) < 0 ||
 	gdev_vector_update_clip_path(vdev, pcpath) < 0 ||
 	gdev_vector_update_log_op(vdev, lop) < 0
 	) 
