--- Intel/topology.c.orig	2010-09-08 12:19:56.000000000 -0700
+++ Intel/topology.c	2010-10-01 03:54:54.000000000 -0700
@@ -20,7 +20,7 @@
  * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
  */
 
-static int fls(int x)
+static int priv_fls(int x)
 {
 	int r = 32;
 
@@ -53,7 +53,7 @@
 {
 	int order;
 
-	order = fls(count) - 1;
+	order = priv_fls(count) - 1;
 	if (count & (count - 1))
 		order++;
 	return order;
