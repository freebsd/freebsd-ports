--- lips/gdevespg.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevespg.c	Fri Dec 17 19:39:57 2004
@@ -142,7 +142,7 @@
     if (pdev->PageCount == 0)
 	escpage_printer_initialize(pdev, fp, num_coipes);
 
-    if (!(lprn->CompBuf = gs_malloc(bpl * 3 / 2 + 1, maxY, "lp2000_print_page_copies(CompBuf)")))
+    if (!(lprn->CompBuf = gs_malloc(pdev->memory, bpl * 3 / 2 + 1, maxY, "lp2000_print_page_copies(CompBuf)")))
 	return_error(gs_error_VMerror);
 
     if (lprn->NegativePrint) {
@@ -154,7 +154,7 @@
     if (code < 0)
 	return code;
 
-    gs_free(lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "lp2000_print_page_copies(CompBuf)");
+    gs_free(pdev->memory, lprn->CompBuf, bpl * 3 / 2 + 1, maxY, "lp2000_print_page_copies(CompBuf)");
 
     if (pdev->Duplex)
 	fprintf(fp, "%c0dpsE", GS);
