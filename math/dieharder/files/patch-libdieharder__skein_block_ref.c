--- libdieharder/skein_block_ref.c.orig	2010-05-16 21:20:59.000000000 -0400
+++ libdieharder/skein_block_ref.c	2010-05-16 21:23:09.000000000 -0400
@@ -121,6 +121,7 @@
 	while (--blkCnt);
 }
 
+#ifdef TSC_TIME
 typedef unsigned long long uint64;
 
 #if 1
@@ -139,4 +140,5 @@
 }
 
 #endif
+#endif
 
