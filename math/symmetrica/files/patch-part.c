--- part.c.orig	2007-12-06 16:30:17 UTC
+++ part.c
@@ -1,5 +1,6 @@
 /* SYMMETRICA V2.0 260298 */
 /* file: part.c */
+/* Patch from SageMath */
 
 #include "def.h"
 #include "macro.h"
@@ -347,7 +348,7 @@ INT append_apply_part(a,b) OP a,b;
     if (a == b) { /* a := a+a */
         if (S_PA_K(a) == VECTOR) {
             erg += append_apply_vector(S_PA_S(a),S_PA_S(b));
-            erg += sort(S_PA_S(a));
+            erg += sym_sort(S_PA_S(a));
             goto endr_ende;
         }
         else if (S_PA_K(a) == EXPONENT) {
@@ -406,7 +407,7 @@ INT append_apply_part(a,b) OP a,b;
             k=S_PA_LI(b)-1;
 /*
             erg += append_apply_vector(S_PA_S(a),S_PA_S(b));
-            erg += sort(S_PA_S(a));
+            erg += sym_sort(S_PA_S(a));
 */
             inc_vector_co(S_PA_S(a),S_PA_LI(b));
             for (j=S_PA_LI(a)-1;j>=0;j--)
@@ -1767,8 +1768,8 @@ static int rec01(INT ni, OP vec)
 /* to compute number of partitions */
 {
     INT erg = OK;
-    if (ni<0) return;
-    if (not EMPTYP(S_V_I(vec,ni))) return;
+    if (ni<0) return NULL;
+    if (not EMPTYP(S_V_I(vec,ni))) return NULL;
     else if (ni<=1) M_I_I(1,S_V_I(vec,ni));
     else {
      
