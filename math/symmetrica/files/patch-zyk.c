--- zyk.c.orig	2007-12-06 16:30:50 UTC
+++ zyk.c
@@ -1,6 +1,7 @@
 
 /* Routinen zur Berechnung von Zykelindikatorpolynomen
  * Nikolaus Schueler 90/91
+ * Patch from SageMath
  */
 #include "def.h"
 #include "macro.h"
@@ -804,7 +805,7 @@ static INT zykelind_arb_co(expztvec,numztvec,pol)
     zykeltypvec = CALLOCOBJECT();
     ak_order = CALLOCOBJECT();
 
-    sum(numztvec,ak_order); /* AK 060295 */
+    sym_sum(numztvec,ak_order); /* AK 060295 */
 
 
 
@@ -1176,7 +1177,7 @@ INT no_orbits_arb(a,b,c) OP a,b,c;
     erg += m_i_i(0,c);
     while (z!=NULL)
         {
-        erg += sum(S_PO_S(z),e);
+        erg += sym_sum(S_PO_S(z),e);
         erg += hoch(b,e,e);
         erg += mult_apply(S_PO_K(z),e);
         erg += add_apply(e,c);
