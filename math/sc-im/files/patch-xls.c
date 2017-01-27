--- xls.c.orig	2016-11-28 12:29:27 UTC
+++ xls.c
@@ -60,7 +60,7 @@ int open_xls(char * fname, char * encodi
         for (c = 0; c <= pWS->rows.lastcol; c++) { // cols
             xlsCell * cell = xls_cell(pWS, r, c);
             //if ((! cell) || (cell->isHidden)) continue;
-            if ((! cell) || (cell->ishiden)) continue; // Unfortunately libxls spells this "ishiden"
+            if ((! cell) || (cell->isHidden)) continue; // Unfortunately libxls spells this "ishiden"
 
             // TODO enable rowspan ?
             //if (cell->rowspan > 1) continue;
