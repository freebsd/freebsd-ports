--- src/gdevlbp8.c.orig	Thu Mar  9 03:40:41 2000
+++ src/gdevlbp8.c
@@ -22,6 +22,8 @@
 
 /* 
   Modifications:
+    3.10.00 Johnny Lam
+            Removed LIPS III code, as it's obsoleted by gdevlips driver.
     2.2.97  Lauri Paatero
             Changed CSI command into ESC [. DCS commands may still need to be changed
             (to ESC P).
@@ -49,7 +51,6 @@
 
 /* The device descriptors */
 private dev_proc_print_page(lbp8_print_page);
-private dev_proc_print_page(lips3_print_page);
 
 gx_device_printer far_data gs_lbp8_device =
   prn_device(prn_std_procs, "lbp8",
@@ -58,14 +59,6 @@
 	0.16, 0.2, 0.32, 0.21,		/* margins: left, bottom, right, top */
 	1, lbp8_print_page);
 
-gx_device_printer far_data gs_lips3_device =
-  prn_device(prn_std_procs, "lips3",
-	82,				/* width_10ths, 8.3" */
-	117,				/* height_10ths, 11.7" */
-	X_DPI, Y_DPI,
-	0.16, 0.27, 0.23, 0.27,		/* margins */
-	1, lips3_print_page);
-
 /* ------ Internal routines ------ */
 
 #define ESC 0x1b
@@ -84,23 +77,6 @@
 
 static const char *lbp8_end = NULL;
 
-static const char lips3_init[] = {
-  ESC, '<', /* soft reset */
-  DCS, '0', 'J', ST, /* JOB END */
-  DCS, '3', '1', ';', '3', '0', '0', ';', '2', 'J', ST, /* 300dpi, LIPS3 JOB START */
-  ESC, '<',  /* soft reset */
-  DCS, '2', 'y', 'P', 'r', 'i', 'n', 't', 'i', 'n', 'g', '(', 'g', 's', ')', ST,  /* Printing (gs) display */
-  ESC, '[', '?', '1', 'l',  /* auto cr-lf disable */
-  ESC, '[', '?', '2', 'h', /* auto ff disable */
-  ESC, '[', '1', '1', 'h', /* set mode */
-  ESC, '[', '7', ' ', 'I', /* select unit size (300dpi)*/
-  ESC, '[', 'f' /* move to home position */
-};
-
-static const char lips3_end[] = {
-  DCS, '0', 'J', ST  /* JOB END */
-};
-
 /* Send the page to the printer.  */
 private int
 can_print_page(gx_device_printer *pdev, FILE *prn_stream,
@@ -203,11 +179,4 @@
 lbp8_print_page(gx_device_printer *pdev, FILE *prn_stream)
 {	return can_print_page(pdev, prn_stream, lbp8_init, sizeof(lbp8_init),
 			      lbp8_end, sizeof(lbp8_end));
-}
-
-/* Print a LIPS III page. */
-private int
-lips3_print_page(gx_device_printer *pdev, FILE *prn_stream)
-{	return can_print_page(pdev, prn_stream, lips3_init, sizeof(lips3_init),
-			      lips3_end, sizeof(lips3_end));
 }
