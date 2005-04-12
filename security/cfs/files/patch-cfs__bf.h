
$FreeBSD$

--- cfs_bf.h.orig
+++ cfs_bf.h
@@ -70,7 +70,7 @@
  * the Alpha, otherwise they will not.  Strangly using the '8 byte'
  * BF_LONG and the default 'non-pointer' inner loop is the best configuration
  * for the Alpha */
-#define BF_LONG unsigned long
+#define BF_LONG unsigned int
 
 #define BF_ROUNDS	16
 #define BF_BLOCK	8
