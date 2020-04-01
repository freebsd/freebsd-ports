--- nu.c.orig	2007-12-06 16:30:16 UTC
+++ nu.c
@@ -1,4 +1,5 @@
 /* FILE:nu.c */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -531,13 +532,13 @@ add_ende:
     ENDR("add");
 }
 
-INT sort(a) OP a;
+INT sym_sort(a) OP a;
 /* sortiert das object in aufsteigender reihenfolge AK 270787 */
 /* AK 160986 */ /* AK 280689 V1.0 */ /* AK 050390 V1.1 */
 /* AK 070891 V1.3 */
 {
     INT erg = OK;
-    EOP("sort(1)",a);
+    EOP("sym_sort(1)",a);
 
     switch(S_O_K(a))
     {
@@ -547,9 +548,9 @@ INT sort(a) OP a;
         erg += sort_vector(a);break;
 #endif /* VECTORTRUE */
     default:
-        erg += WTO("sort",a); break;
+        erg += WTO("sym_sort",a); break;
     };
-    ENDR("sort");
+    ENDR("sym_sort");
 }
 
 INT length(a,d) OP a,d;
@@ -641,7 +642,7 @@ INT content(a,b) OP a,b;
     ENDR("content");
 }
 
-INT sum(a,res) OP a,res;
+INT sym_sum(a,res) OP a,res;
 /* AK 280689 V1.0 */ /* AK 050390 V1.1 */ /* AK 120391 V1.2 */
 /* AK 140891 V1.3 */
 /* AK 170298 V2.0 */
@@ -649,7 +650,7 @@ INT sum(a,res) OP a,res;
     INT erg = OK;
     COP("sum(1)",a);
     COP("sum(2)",res);
-    CE2(a,res,sum);
+    CE2(a,res,sym_sum);
 
     switch(S_O_K(a))
     {
@@ -680,7 +681,7 @@ INT sum(a,res) OP a,res;
         erg += WTO("sum",a); break;
     };
 
-    ENDR("sum");
+    ENDR("sym_sum");
 }
 
 
