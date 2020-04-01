--- nc.c.orig	2007-12-06 16:30:15 UTC
+++ nc.c
@@ -1,4 +1,5 @@
 /* nc.c SYMMETRICA source code */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -204,7 +205,7 @@ INT scalarproduct_nc(a,b,c) OP a,b,c;
     erg += mult(S_NC_C(a),S_NC_C(b),d);
     erg += m_gl_co(S_NC_GL(a),e);
     erg += mult_apply(e,d);
-    erg += sum(d,e);
+    erg += sym_sum(d,e);
     erg += m_gl_go(S_NC_GL(a),d);
     erg += div(e,d,c);
     erg += freeall(e);
@@ -617,7 +618,7 @@ INT reduce_nc_kranz(a,b) OP a,b;
         erg += mult_nc_kranz(c,a,e);
         erg += mult(S_V_I(e,1L),f,c);
         erg += div(c,g,c);
-        erg += sum(c,S_V_I(S_NC_C(b),S_I_I(d)));
+        erg += sym_sum(c,S_V_I(S_NC_C(b),S_I_I(d)));
     }
     erg += freeall(c); 
     erg += freeall(d); 
@@ -712,7 +713,7 @@ INT m_vcl_kranz(l,a) OP l,a;
     for(j = 0L; j<S_V_LI(c);j++) {
         kranztypus_to_matrix(S_V_I(c,j),S_V_I(a,j)); 
     }
-    sort(a);
+    sym_sort(a);
     freeall(f); freeall(h); freeall(c);
     return OK;
 }
@@ -739,7 +740,7 @@ INT m_vco_kranz(l,a) OP l,a;
         kranztypus_to_matrix(S_V_I(c,j),S_V_I(h,j)); 
         }
     
-    sort(h); 
+    sym_sort(h); 
     m_l_v(S_V_L(h),a);
     for(j = 0L; j<S_V_LI(c);j++) {
         typusorder(S_V_I(h,j), zb, za, S_V_I(a,j), f);
@@ -789,7 +790,7 @@ INT order_class_kranz(l,i,a) OP l,i,a;
         erg += kranztypus_to_matrix(S_V_I(c,j),S_V_I(h,j)); 
     }
     
-    erg += sort(h);
+    erg += sym_sort(h);
     erg += typusorder(S_V_I(h,S_I_I(i)), zb, za, a, f);
     erg += freeall(f); 
     erg += freeall(c); 
