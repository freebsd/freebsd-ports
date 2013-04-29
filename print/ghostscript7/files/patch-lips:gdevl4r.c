--- lips/gdevl4r.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevl4r.c	Tue Jan 13 01:28:40 2004
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
