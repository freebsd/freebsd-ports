--- alclib/fec.c.orig	Fri Feb 13 15:58:54 2004
+++ alclib/fec.c	Fri Feb 13 15:58:54 2004
@@ -268,8 +268,7 @@
     return p ;
 }
 
-#define NEW_GF_MATRIX(rows, cols) \
-    (gf *)my_malloc(rows * cols * sizeof(gf), " ## __LINE__ ## " )
+#define NEW_GF_MATRIX(rows, cols) (gf *)my_malloc(rows * cols * sizeof(gf), " ## __LINE__ ## " )
 
 /*
  * initialize the data structures used for computations in GF.
@@ -350,8 +349,7 @@
  * 
  * Note that gcc on
  */
-#define addmul(dst, src, c, sz) \
-    if (c != 0) addmul1(dst, src, c, sz)
+#define addmul(dst, src, c, sz)  if (c != 0) addmul1(dst, src, c, sz)
 
 #define UNROLL 16 /* 1, 4, 8, 16 */
 static void
