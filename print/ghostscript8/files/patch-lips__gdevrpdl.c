--- lips/gdevrpdl.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevrpdl.c	Fri Dec 31 17:34:04 2004
@@ -81,7 +81,7 @@
     if (pdev->PageCount == 0)
 	rpdl_printer_initialize(pdev, prn_stream, num_coipes);
 
-    if (!(lprn->CompBuf = gs_malloc(bpl * 3 / 2 + 1, maxY, "rpdl_print_page_copies(CompBuf)")))
+    if (!(lprn->CompBuf = gs_malloc(pdev->memory, bpl * 3 / 2 + 1, maxY, "rpdl_print_page_copies(CompBuf)")))
 	return_error(gs_error_VMerror);
 
     lprn->NegativePrint = false; /* Not Support */
@@ -90,7 +90,7 @@
     if (code < 0)
 	return code;
 
-    gs_free(lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "rpdl_print_page_copies(CompBuf)");
+    gs_free(pdev->memory, lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "rpdl_print_page_copies(CompBuf)");
 
     fprintf(prn_stream, "\014");	/* Form  Feed */
 
