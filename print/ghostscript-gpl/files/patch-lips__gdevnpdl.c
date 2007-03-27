--- lips/gdevnpdl.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevnpdl.c	Fri Dec 31 17:32:52 2004
@@ -582,7 +582,7 @@
     int code;
     int maxY = lprn->BlockLine / lprn->nBh * lprn->nBh;
 
-    if (!(lprn->CompBuf = gs_malloc(line_size * maxY, sizeof(byte), "npdl_print_page_copies(CompBuf)")))
+    if (!(lprn->CompBuf = gs_malloc(pdev->memory, line_size * maxY, sizeof(byte), "npdl_print_page_copies(CompBuf)")))
 	return_error(gs_error_VMerror);
 
 
@@ -680,7 +680,7 @@
     /* Form Feed */
     fputs("\014", prn_stream);
 
-    gs_free(lprn->CompBuf, line_size * maxY, sizeof(byte), "npdl_print_page_copies(CompBuf)");
+    gs_free(pdev->memory, lprn->CompBuf, line_size * maxY, sizeof(byte), "npdl_print_page_copies(CompBuf)");
     return 0;
 }
 
