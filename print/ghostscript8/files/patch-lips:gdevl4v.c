--- lips/gdevl4v.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevl4v.c	Tue Jan 13 01:30:38 2004
@@ -230,41 +230,66 @@
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
+#if GS_VERSION_MAJOR >= 8
+private int lips4v_beginpage(gx_device_vector * vdev);
+private int lips4v_setfillcolor(gx_device_vector * vdev,
+				   const gx_drawing_color * pdc);
+private int lips4v_setstrokecolor(gx_device_vector * vdev,
+				     const gx_drawing_color * pdc);
+private int lips4v_setdash(gx_device_vector * vdev, const float *pattern,
+			      uint count, floatp offset);
+private int lips4v_setflat(gx_device_vector * vdev, floatp flatness);
+private int
+lips4v_setlogop(gx_device_vector * vdev, gs_logical_operation_t lop,
+		 gs_logical_operation_t diff);
 private int
-lips4v_setlogop(P3
 
-		(gx_device_vector * vdev, gs_logical_operation_t lop,
-		 gs_logical_operation_t diff));
+lips4v_beginpath(gx_device_vector * vdev, gx_path_type_t type);
+private int
+lips4v_moveto(gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
+	       floatp y, gx_path_type_t type);
 private int
+lips4v_lineto(gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
+	       floatp y, gx_path_type_t type);
+private int
+lips4v_curveto(gx_device_vector * vdev, floatp x0, floatp y0, floatp x1,
+		floatp y1, floatp x2, floatp y2, floatp x3, floatp y3,
+		gx_path_type_t type);
+lips4v_closepath(gx_device_vector * vdev, floatp x, floatp y, floatp x_start,
+		  floatp y_start, gx_path_type_t type);
 
-lips4v_beginpath(P2(gx_device_vector * vdev, gx_path_type_t type));
+private int lips4v_endpath(gx_device_vector * vdev, gx_path_type_t type);
+#else
+private int lips4v_beginpage(P1(gx_device_vector * vdev));
+private int lips4v_setfillcolor(gx_device_vector * vdev,
+				   const gx_drawing_color * pdc);
+private int lips4v_setstrokecolor(gx_device_vector * vdev,
+				     const gx_drawing_color * pdc);
+private int lips4v_setdash(gx_device_vector * vdev, const float *pattern,
+			      uint count, floatp offset);
+private int lips4v_setflat(gx_device_vector * vdev, floatp flatness);
+private int
+lips4v_setlogop(gx_device_vector * vdev, gs_logical_operation_t lop,
+		 gs_logical_operation_t diff);
+private int
+
+lips4v_beginpath(gx_device_vector * vdev, gx_path_type_t type);
 private int
-lips4v_moveto(P6
-	      (gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
-	       floatp y, gx_path_type_t type));
+lips4v_moveto(gx_device_vector * vdev, floatp x0, floatp y0, floatp x,
+	       floatp y, gx_path_type_t type);
 private int
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
+#endif
 private int lips4v_setlinewidth(gx_device_vector * vdev, floatp width);
 private int lips4v_setlinecap(gx_device_vector * vdev, gs_line_cap cap);
 private int lips4v_setlinejoin(gx_device_vector * vdev, gs_line_join join);
@@ -758,10 +783,26 @@
     /* 用紙サイズ */
     if (pdev->prev_paper_size != paper_size) {
 	if (paper_size == USER_SIZE) {
-	    sprintf(paper, "%c80;%d;%dp", LIPS_CSI, width * 10, height * 10);
+	    /* modified by shige 06/27 2003
+	    sprintf(paper, "%c80;%d;%dp", LIPS_CSI, width * 10, height * 10); */
+	    /* modified by shige 11/09 2003
+	    sprintf(paper, "%c80;%d;%dp", LIPS_CSI, height * 10, width * 10); */
+	    sprintf(paper, "%c80;%d;%dp", LIPS_CSI, 
+		    (height * 10 > LIPS_HEIGHT_MAX_720)? 
+		    LIPS_HEIGHT_MAX_720 : (height * 10),
+		    (width * 10 > LIPS_WIDTH_MAX_720)? 
+		    LIPS_WIDTH_MAX_720 : (width * 10));
 	    lputs(s, paper);
 	} else if (paper_size == USER_SIZE + LANDSCAPE) {
-	    sprintf(paper, "%c81;%d;%dp", LIPS_CSI, height * 10, width * 10);
+	    /* modified by shige 06/27 2003
+	    sprintf(paper, "%c81;%d;%dp", LIPS_CSI, height * 10, width * 10); */
+	    /* modified by shige 11/09 2003
+	    sprintf(paper, "%c81;%d;%dp", LIPS_CSI, width * 10, height * 10); */
+	    sprintf(paper, "%c80;%d;%dp", LIPS_CSI, 
+		    (width * 10 > LIPS_HEIGHT_MAX_720)? 
+		    LIPS_HEIGHT_MAX_720 : (width * 10),
+		    (height * 10 > LIPS_WIDTH_MAX_720)? 
+		    LIPS_WIDTH_MAX_720 : (height * 10));
 	    lputs(s, paper);
 	} else {
 	    sprintf(paper, "%c%dp", LIPS_CSI, paper_size);
@@ -770,12 +811,28 @@
     } else if (paper_size == USER_SIZE) {
 	if (pdev->prev_paper_width != width ||
 	    pdev->prev_paper_height != height)
-		sprintf(paper, "%c80;%d;%dp", LIPS_CSI, width * 10, height * 10);
+	  	/* modified by shige 06/27 2003
+		sprintf(paper, "%c80;%d;%dp", LIPS_CSI, width * 10, height * 10); */
+		/* modified by shige 11/09 2003
+		sprintf(paper, "%c80;%d;%dp", LIPS_CSI, height * 10, width * 10); */
+		sprintf(paper, "%c80;%d;%dp", LIPS_CSI, 
+		    (height * 10 > LIPS_HEIGHT_MAX_720)? 
+		    LIPS_HEIGHT_MAX_720 : (height * 10),
+		    (width * 10 > LIPS_WIDTH_MAX_720)? 
+		    LIPS_WIDTH_MAX_720 : (width * 10));
 	lputs(s, paper);
     } else if (paper_size == USER_SIZE + LANDSCAPE) {
 	if (pdev->prev_paper_width != width ||
 	    pdev->prev_paper_height != height)
-		sprintf(paper, "%c81;%d;%dp", LIPS_CSI, height * 10, width * 10);
+		/* modified by shige 06/27 2003
+		sprintf(paper, "%c81;%d;%dp", LIPS_CSI, height * 10, width * 10); */
+	  	/* modified by shige 11/09 2003
+		sprintf(paper, "%c81;%d;%dp", LIPS_CSI, width * 10, height * 10); */
+		sprintf(paper, "%c80;%d;%dp", LIPS_CSI, 
+		    (width * 10 > LIPS_HEIGHT_MAX_720)? 
+		    LIPS_HEIGHT_MAX_720 : (width * 10),
+		    (height * 10 > LIPS_WIDTH_MAX_720)? 
+		    LIPS_WIDTH_MAX_720 : (height * 10));
 	lputs(s, paper);
     }
     pdev->prev_paper_size = paper_size;
@@ -1881,7 +1938,7 @@
 	}
 	color_set_pure(&color, one);
 	code = gdev_vector_update_fill_color((gx_device_vector *) pdev,
-					     &color);
+					     NULL, &color);
     }
     if (code < 0)
 	return 0;
@@ -2026,7 +2083,7 @@
     if (w <= 0 || h <= 0)
 	return 0;
     if (depth > 1 ||
-	gdev_vector_update_fill_color(vdev, pdcolor) < 0 ||
+	gdev_vector_update_fill_color(vdev, NULL, pdcolor) < 0 ||
 	gdev_vector_update_clip_path(vdev, pcpath) < 0 ||
 	gdev_vector_update_log_op(vdev, lop) < 0)
 	return gx_default_fill_mask(dev, data, data_x, raster, id,
