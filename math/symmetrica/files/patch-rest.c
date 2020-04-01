--- rest.c.orig	2007-12-06 16:30:31 UTC
+++ rest.c
@@ -1,4 +1,5 @@
 /* SYMMETRICA file:rest.c */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -3998,7 +3999,7 @@ aaa:
                 oj = j;
                 }
         }
-    erg += sum(c,b);
+    erg += sym_sum(c,b);
 eee:
     erg += freeall(c);
     ENDR("charge_word");
