--- lips/gdevl4r.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevl4r.c	Fri Dec 17 19:19:02 2004
@@ -53,8 +53,8 @@
 #define lips_device(dtype, procs, dname, xdpi, ydpi, lm, bm, rm, tm, color_bits,\
 		    print_page_copies, image_out, cassetFeed, username)\
 {        std_device_std_color_full_body(dtype, &procs, dname,\
-          (int)((long)(DEFAULT_WIDTH_10THS) * (xdpi) / 10),\
-          (int)((long)(DEFAULT_HEIGHT_10THS) * (ydpi) / 10),\
+          (int)((long)((DEFAULT_WIDTH_10THS) * (xdpi)) / 10),\
+          (int)((long)((DEFAULT_HEIGHT_10THS) * (ydpi)) / 10),\
           xdpi, ydpi, color_bits,\
           -(lm) * (xdpi), -(tm) * (ydpi),\
           (lm) * 72.0, (bm) * 72.0,\
@@ -68,8 +68,8 @@
 #define lips4_device(dtype, procs, dname, xdpi, ydpi, lm, bm, rm, tm, color_bits,\
 		    print_page_copies, image_out, cassetFeed, username)\
 {        std_device_std_color_full_body(dtype, &procs, dname,\
-          (int)((long)(DEFAULT_WIDTH_10THS) * (xdpi) / 10),\
-          (int)((long)(DEFAULT_HEIGHT_10THS) * (ydpi) / 10),\
+          (int)((long)((DEFAULT_WIDTH_10THS) * (xdpi)) / 10),\
+          (int)((long)((DEFAULT_HEIGHT_10THS) * (ydpi)) / 10),\
           xdpi, ydpi, color_bits,\
           -(lm) * (xdpi), -(tm) * (ydpi),\
           (lm) * 72.0, (bm) * 72.0,\
@@ -178,8 +178,13 @@
 private int lips4c_output_page(gx_device_printer * pdev, FILE * prn_stream);
 private int lips_delta_encode(byte * inBuff, byte * prevBuff, byte * outBuff, byte * diffBuff, int Length);
 private int lips_byte_cat(byte * TotalBuff, byte * Buff, int TotalLen, int Len);
+#if GS_VERSION_MAJOR >= 8
+private int lips_print_page_copies(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies);
+private int lips_print_page_copies(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies);
+#else
 private int lips_print_page_copies(P4(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies));
 private int lips_print_page_copies(P4(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies));
+#endif
 private int lips4type_print_page_copies(gx_device_printer * pdev, FILE * prn_stream, int num_copies, int ptype);
 
 private int
@@ -597,7 +602,7 @@
     /* Initialize printer. */
     lips_job_start(pdev, ptype, prn_stream, num_copies);
 
-    if (!(lprn->CompBuf = gs_malloc(bpl * 3 / 2 + 1, maxY, "(CompBuf)")))
+    if (!(lprn->CompBuf = gs_malloc(pdev->memory, bpl * 3 / 2 + 1, maxY, "(CompBuf)")))
 	return_error(gs_error_VMerror);
 
 
@@ -607,7 +612,7 @@
     if (code < 0)
 	return code;
 
-    gs_free(lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "(CompBuf)");
+    gs_free(pdev->memory, lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "(CompBuf)");
 
     /* eject page */
     lips_job_end(pdev, prn_stream);
@@ -641,9 +646,9 @@
 
     if (pdev->color_info.depth == 1)
       {
-	if (!(lprn->CompBuf = gs_malloc(bpl * 3 / 2 + 1, maxY, "(CompBuf)")))
+	if (!(lprn->CompBuf = gs_malloc(pdev->memory, bpl * 3 / 2 + 1, maxY, "(CompBuf)")))
 	  return_error(gs_error_VMerror);
-	if (!(lprn->CompBuf2 = gs_malloc(bpl * 3 / 2 + 1, maxY, "(CompBuf2)")))
+	if (!(lprn->CompBuf2 = gs_malloc(pdev->memory, bpl * 3 / 2 + 1, maxY, "(CompBuf2)")))
 	  return_error(gs_error_VMerror);
 
 	if (lprn->NegativePrint) {
@@ -663,8 +668,8 @@
 	if (code < 0)
 	  return code;
 	
-	gs_free(lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "(CompBuf)");
-	gs_free(lprn->CompBuf2, bpl * 3 / 2 + 1, maxY, "(CompBuf2)");
+	gs_free(pdev->memory, lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "(CompBuf)");
+	gs_free(pdev->memory, lprn->CompBuf2, bpl * 3 / 2 + 1, maxY, "(CompBuf2)");
       }
     else
       {
@@ -903,15 +908,15 @@
     int lnum = 0;
 
     /* Memory Allocate */
-    if (!(pBuff = (byte *) gs_malloc(nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(pBuff)")))
+    if (!(pBuff = (byte *) gs_malloc(pdev->memory, nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(pBuff)")))
 	return_error(gs_error_VMerror);
-    if (!(prevBuff = (byte *) gs_malloc(nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(prevBuff)")))
+    if (!(prevBuff = (byte *) gs_malloc(pdev->memory, nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(prevBuff)")))
 	return_error(gs_error_VMerror);
-    if (!(ComBuff = (byte *) gs_malloc(Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128, sizeof(byte), "lips4c_compress_output_page(ComBuff)")))
+    if (!(ComBuff = (byte *) gs_malloc(pdev->memory, Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128, sizeof(byte), "lips4c_compress_output_page(ComBuff)")))
 	return_error(gs_error_VMerror);
-    if (!(TotalBuff = (byte *) gs_malloc((Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128) * NUM_LINES_4C, sizeof(byte), "lips4c_compress_output_page(TotalBuff)")))
+    if (!(TotalBuff = (byte *) gs_malloc(pdev->memory, (Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128) * NUM_LINES_4C, sizeof(byte), "lips4c_compress_output_page(TotalBuff)")))
 	return_error(gs_error_VMerror);
-    if (!(diffBuff = (byte *) gs_malloc(Xpixel * num_components * 2, sizeof(byte), "lips_print_page")))
+    if (!(diffBuff = (byte *) gs_malloc(pdev->memory, Xpixel * num_components * 2, sizeof(byte), "lips_print_page")))
 	return_error(gs_error_VMerror);
 
     /* make output data */
@@ -927,11 +932,11 @@
 			    pdev->height - (lnum - NUM_LINES_4C));
     }
     /* Free Memory */
-    gs_free(pBuff, nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(pBuff)");
-    gs_free(prevBuff, nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(prevBuff)");
-    gs_free(ComBuff, Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128, sizeof(byte), "lips4c_compress_output_page(ComBuff)");
-    gs_free(TotalBuff, (Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128) * NUM_LINES_4C, sizeof(byte), "lips4c_compress_output_page(TotalBuff)");
-    gs_free(diffBuff, Xpixel * num_components * 2, sizeof(byte), "lips_print_page");
+    gs_free(pdev->memory, pBuff, nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(pBuff)");
+    gs_free(pdev->memory, prevBuff, nBytesPerLine, sizeof(byte), "lips4c_compress_output_page(prevBuff)");
+    gs_free(pdev->memory, ComBuff, Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128, sizeof(byte), "lips4c_compress_output_page(ComBuff)");
+    gs_free(pdev->memory, TotalBuff, (Xpixel * num_components + (Xpixel * num_components + 127) * 129 / 128) * NUM_LINES_4C, sizeof(byte), "lips4c_compress_output_page(TotalBuff)");
+    gs_free(pdev->memory, diffBuff, Xpixel * num_components * 2, sizeof(byte), "lips_print_page");
 
     return 0;
 }
@@ -1065,11 +1070,25 @@
 	if (paper_size == USER_SIZE) {
 	    fprintf(prn_stream, "%c2 I", LIPS_CSI);
 	    fprintf(prn_stream, "%c80;%d;%dp", LIPS_CSI,
-		    width * 10, height * 10);
+		    /* modified by shige 06/27 2003
+		    width * 10, height * 10); */
+		    /* modified by shige 11/09 2003
+		    height * 10, width * 10); */
+		    (height * 10 > LIPS_HEIGHT_MAX_720)?
+		    LIPS_HEIGHT_MAX_720 : (height * 10),
+		    (width * 10 > LIPS_WIDTH_MAX_720)?
+		    LIPS_WIDTH_MAX_720 : (width * 10));
 	} else if (paper_size == USER_SIZE + LANDSCAPE) {
 	    fprintf(prn_stream, "%c2 I", LIPS_CSI);
 	    fprintf(prn_stream, "%c81;%d;%dp", LIPS_CSI,
-		    height * 10, width * 10);
+		    /* modified by shige 06/27 2003
+		    width * 10, height * 10); */
+		    /* modified by shige 11/09 2003
+		    width * 10, height * 10); */
+		    (width * 10 > LIPS_HEIGHT_MAX_720)?
+		    LIPS_HEIGHT_MAX_720 : (width * 10),
+		    (height * 10 > LIPS_WIDTH_MAX_720)?
+		    LIPS_WIDTH_MAX_720 : (height * 10));
 	} else {
 	    fprintf(prn_stream, "%c%dp", LIPS_CSI, paper_size);
 	}
@@ -1078,14 +1097,28 @@
 	    prev_paper_height != height) {
 	    fprintf(prn_stream, "%c2 I", LIPS_CSI);
 	    fprintf(prn_stream, "%c80;%d;%dp", LIPS_CSI,
-		    width * 10, height * 10);
+		    /* modified by shige 06/27 2003
+		    width * 10, height * 10); */
+		    /* modified by shige 11/09 2003
+		    height * 10, width * 10); */
+		    (height * 10 > LIPS_HEIGHT_MAX_720)?
+		    LIPS_HEIGHT_MAX_720 : (height * 10),
+		    (width * 10 > LIPS_WIDTH_MAX_720)?
+		    LIPS_WIDTH_MAX_720 : (width * 10));
 	}
     } else if (paper_size == USER_SIZE + LANDSCAPE) {
 	if (prev_paper_width != width ||
 	    prev_paper_height != height) {
 	    fprintf(prn_stream, "%c2 I", LIPS_CSI);
 	    fprintf(prn_stream, "%c81;%d;%dp", LIPS_CSI,
-		    height * 10, width * 10);
+		    /* modified by shige 06/27 2003
+		    height * 10, width * 10); */
+		    /* modified by shige 11/09 2003
+		    width * 10, height * 10); */
+		    (width * 10 > LIPS_HEIGHT_MAX_720)?
+		    LIPS_HEIGHT_MAX_720 : (width * 10),
+		    (height * 10 > LIPS_WIDTH_MAX_720)?
+		    LIPS_WIDTH_MAX_720 : (height * 10));
 	}
     }
     /* desired number of copies */
