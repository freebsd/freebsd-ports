--- src/cpca_gdevl4v.c.orig	Tue May  7 00:30:00 2002
+++ src/cpca_gdevl4v.c	Fri Dec  6 04:59:34 2002
@@ -316,41 +316,35 @@
 };
 
 /* Vector device implementation */
-private int lips4v_beginpage(P1(gx_device_vector * vdev));
-private int lips4v_setfillcolor(P2(gx_device_vector * vdev,
-				   const gx_drawing_color * pdc));
-private int lips4v_setstrokecolor(P2(gx_device_vector * vdev,
-				     const gx_drawing_color * pdc));
-private int lips4v_setdash(P4(gx_device_vector * vdev, const float *pattern,
-			      uint count, floatp offset));
-private int lips4v_setflat(P2(gx_device_vector * vdev, floatp flatness));
+private int lips4v_beginpage(gx_device_vector * vdev);
+private int lips4v_setfillcolor(gx_device_vector * vdev,
+				   const gx_drawing_color * pdc);
+private int lips4v_setstrokecolor(gx_device_vector * vdev,
+				     const gx_drawing_color * pdc);
+private int lips4v_setdash(gx_device_vector * vdev, const float *pattern,
+			      uint count, floatp offset);
+private int lips4v_setflat(gx_device_vector * vdev, floatp flatness);
 private int
-lips4v_setlogop(P3
-
-		(gx_device_vector * vdev, gs_logical_operation_t lop,
-		 gs_logical_operation_t diff));
+lips4v_setlogop(gx_device_vector * vdev, gs_logical_operation_t lop,
+		 gs_logical_operation_t diff);
 private int
 
-lips4v_beginpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+lips4v_beginpath(gx_device_vector * vdev, gx_path_type_t type);
+private int
+lips4v_moveto(gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
+	       floatp y, gx_path_type_t type);
 private int
-lips4v_moveto(P6
-	      (gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
-	       floatp y, gx_path_type_t type));
-private int
-lips4v_lineto(P6
-	      (gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
-	       floatp y, gx_path_type_t type));
+lips4v_lineto(gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
+	       floatp y, gx_path_type_t type);
 private int
-lips4v_curveto(P10
-	       (gx_device_vector * vdev, floatp x0, floatp y0, floatp x1,
+lips4v_curveto(gx_device_vector * vdev, floatp x0, floatp y0, floatp x1,
 		floatp y1, floatp x2, floatp y2, floatp x3, floatp y3,
-		gx_path_type_t type));
+		gx_path_type_t type);
 private int
-lips4v_closepath(P6
-		 (gx_device_vector * vdev, floatp x, floatp y, floatp x_start,
-		  floatp y_start, gx_path_type_t type));
+lips4v_closepath(gx_device_vector * vdev, floatp x, floatp y, floatp x_start,
+		  floatp y_start, gx_path_type_t type);
 
-private int lips4v_endpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+private int lips4v_endpath(gx_device_vector * vdev, gx_path_type_t type);
 private int lips4v_setlinewidth(gx_device_vector * vdev, floatp width);
 private int lips4v_setlinecap(gx_device_vector * vdev, gs_line_cap cap);
 private int lips4v_setlinejoin(gx_device_vector * vdev, gs_line_join join);
