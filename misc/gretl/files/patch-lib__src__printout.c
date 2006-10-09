--- lib/src/printout.c.orig	Fri Sep  8 02:15:00 2006
+++ lib/src/printout.c	Sun Oct  8 01:52:29 2006
@@ -400,11 +400,11 @@
 void print_xtab (const Xtab *tab, gretlopt opt, PRN *prn)
 {
     int i, j, r, c;
-    r = tab->rows;
-    c = tab->cols;
     double x, y;
     int n5 = 0;
     double pearson = 0.0;
+    r = tab->rows;
+    c = tab->cols;
 
     pputc(prn, '\n');
     pprintf(prn, _("Cross-tabulation of %s (rows) against %s (columns)"),
