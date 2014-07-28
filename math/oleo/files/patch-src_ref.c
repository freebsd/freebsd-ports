--- src/ref.c.orig	Wed Feb 14 08:38:06 2001
+++ src/ref.c	Sat Jul 19 13:51:39 2003
@@ -263,7 +263,7 @@
 read_new_value (CELLREF row, CELLREF col, char *form, char *val)
 {
   unsigned char *new_bytes;
-  extern double __plinf, __neinf, __nan;
+  extern double __plinf, __neinf, ___nan;
 
   cur_row = row;
   cur_col = col;
@@ -348,7 +348,7 @@
 	  else if (!stricmp (nname, val))
 	    {
 	      SET_TYP (my_cell, TYP_FLT);
-	      my_cell->cell_flt = __nan;
+	      my_cell->cell_flt = ___nan;
 	    }
 	  else
 	    {
