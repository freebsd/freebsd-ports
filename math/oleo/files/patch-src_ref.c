--- src/ref.c.orig	2001-02-13 23:38:06 UTC
+++ src/ref.c
@@ -263,7 +263,7 @@ char *
 read_new_value (CELLREF row, CELLREF col, char *form, char *val)
 {
   unsigned char *new_bytes;
-  extern double __plinf, __neinf, __nan;
+  extern double __plinf, __neinf, ___nan;
 
   cur_row = row;
   cur_col = col;
@@ -348,7 +348,7 @@ read_new_value (CELLREF row, CELLREF col
 	  else if (!stricmp (nname, val))
 	    {
 	      SET_TYP (my_cell, TYP_FLT);
-	      my_cell->cell_flt = __nan;
+	      my_cell->cell_flt = ___nan;
 	    }
 	  else
 	    {
