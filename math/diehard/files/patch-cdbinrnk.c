--- cdbinrnk.c.orig	2019-08-03 09:50:12 UTC
+++ cdbinrnk.c
@@ -13,6 +13,8 @@ typedef struct binmatrix {
 
 } binmatrix;
 
+#include <string.h>
+
 /*print the title*/
 void rnk_ttl(char *fn, char *test)
 {
@@ -162,7 +164,7 @@ real rnk_stat(char *fn, counter no_mtr, 
     Ef=no_mtr* ( *(p+i) );
     tmp=(f[i]-Ef)*(f[i]-Ef)/Ef;
     chsq+=tmp;
-    printf("\t%s%d\t%-12d\t%-12.1f", cat[MIN(1,i)], i+llim, f[i], Ef);
+    printf("\t%s%lu\t%-12lu\t%-12.1f", cat[MIN(1,i)], i+llim, f[i], Ef);
     printf("\t%-12.3f\t%-12.3f\n", tmp, chsq);
   }
   uni("close");
