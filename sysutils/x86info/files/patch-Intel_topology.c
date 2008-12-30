--- Intel/topology.c.orig	2008-12-30 22:21:53.000000000 +0300
+++ Intel/topology.c	2008-12-30 22:22:23.000000000 +0300
@@ -20,7 +20,7 @@
  * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
  */
 
-static int fls(int x)
+static int priv_fls(int x)
 {
 	int r = 32;
 
@@ -55,7 +55,7 @@
 {
 	unsigned int MaskWidth = 0;
 
-	MaskWidth = fls(item)-1;
+	MaskWidth = priv_fls(item)-1;
 	return MaskWidth;
 }
 
