--- galois.c.orig	2007-12-06 16:30:01 UTC
+++ galois.c
@@ -1,3 +1,5 @@
+/* Patch from SageMath */
+
 #include "def.h"
 #include "macro.h"
 
@@ -758,7 +760,7 @@ nn:
 		}
         }
     FREEALL2(v,nv);
-    sort(res);
+    sym_sort(res);
     }
     S3R(k,phg_c,phg_d,"all_points_phg_store",res);
     ENDR("all_points");
