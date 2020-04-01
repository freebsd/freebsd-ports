--- bar.c.orig	2007-12-06 16:29:59 UTC
+++ bar.c
@@ -1,4 +1,5 @@
 /* file bar.c symmetrica */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -237,7 +238,7 @@ INT rz_lehmercode_bar(a,b) OP a,b;
     g = callocobject();
     e = S_V_I(a,0L);
     f = S_V_I(a,1L);
-    erg += sum(f,g);
+    erg += sym_sum(f,g);
     j=0L;
     for (i=0L;i<S_V_LI(e);i++)
         j += S_V_II(e,i)*(i+1L);
@@ -427,7 +428,7 @@ INT makevectorof_class_bar(a,b) OP a,b;
     for (i=0L;i<S_V_LI(b);i++)
         erg += kranztypus_to_matrix(S_V_I(c,i),S_V_I(b,i));
     erg += freeall(c);
-    erg += sort(b); /* AK 130592 */
+    erg += sym_sort(b); /* AK 130592 */
     ENDR("makevectorof_class_bar");
 }
 
@@ -615,7 +616,7 @@ INT length_bar(a,b) OP a,b;
     c = callocobject();
     d = callocobject();
     erg += lehmercode_bar(a,c);
-    erg += sum(S_V_I(c,1L),b);
+    erg += sym_sum(S_V_I(c,1L),b);
     for(i=0L;i<S_P_LI(a);i++)
         {
         if (S_V_II(S_V_I(c,0L),i) == 1L)
