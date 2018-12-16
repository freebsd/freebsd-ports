--- include/CombBLAS/mmio.h.orig	2018-12-16 06:16:28 UTC
+++ include/CombBLAS/mmio.h
@@ -13,6 +13,8 @@
 #define MatrixMarketBanner "%%MatrixMarket"
 #define MM_MAX_TOKEN_LENGTH 64
 
+#include <sys/types.h>
+
 typedef char MM_typecode[4];
 
 char *mm_typecode_to_str(MM_typecode matcode);
