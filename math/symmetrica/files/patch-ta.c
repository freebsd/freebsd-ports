--- ta.c.orig	2007-12-06 16:30:36 UTC
+++ ta.c
@@ -1,4 +1,5 @@
 /* SYMMETRICA file:ta.c */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -1596,7 +1597,7 @@ aaa:
     {
     OP d,e;
     e = CALLOCOBJECT();
-    erg += sum(content,e); /* AK 271098 */
+    erg += sym_sum(content,e); /* AK 271098 */
     d = CALLOCOBJECT();
     erg += weight(shape,d);
     if (NEQ(d,e))
@@ -1821,7 +1822,7 @@ INT matrix_twoword(matrix, column_index, row_index) 
     CE3(matrix, column_index, row_index,matrix_twoword);
     c = callocobject();
     erg += zeilen_summe(matrix,c);
-    erg += sum(c,c);
+    erg += sym_sum(c,c);
     erg += m_l_v(c,column_index);
     erg += m_l_v(c,row_index);
     for(i=0,l=0;i<S_M_HI(matrix);i++)
