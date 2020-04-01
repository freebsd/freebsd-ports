--- perm.c.orig	2007-12-06 16:30:19 UTC
+++ perm.c
@@ -1,4 +1,5 @@
 /* SYMMETRICA perm.c */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -833,9 +834,9 @@ komponeten. */
     /* s = Anzahl der spalten */
         
     s = S_V_LI(S_V_I(a,0L));
-    sum(S_V_I(a,0L),summe);/* composition ist vector */
+    sym_sum(S_V_I(a,0L),summe);/* composition ist vector */
     z = S_I_I(summe);
-    FREEALL(summe); 
+    FREEALL(summe);
     m_ilih_nm(s,z,b); 
     C_O_K(b,KRANZTYPUS);
     for (i=0L;i<s;i++)
@@ -1114,7 +1115,7 @@ h wird der vektor der label der konjugiertenklassen */
         erg += kranztypus_to_matrix(S_V_I(c,i),S_V_I(h,i)); 
     }
     
-    erg += sort(h);
+    erg += sym_sort(h);
 
     erg += chartafel(b,ct);
 
@@ -1926,7 +1927,7 @@ INT numberof_inversionen(a,b) OP a,b;
     OP c;
     c = CALLOCOBJECT();
     erg += lehmercode_permutation(a,c); /*result is a vector */
-    erg += sum(c,b); 
+    erg += sym_sum(c,b); 
     FREEALL(c);
     }
     ENDR("numberof_inversionen");
@@ -2364,7 +2365,7 @@ vgl verfahren 1 in diplomarbeit */
     COP("rz_lehmercode(2)",b);
 
     zw = callocobject();
-    erg += sum(lc,zw); 
+    erg += sym_sum(lc,zw); 
     if (NULLP(zw)) 
         {
         erg += m_il_integervector((INT)0,b);
