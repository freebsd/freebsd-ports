--- Intel/topology.c.orig	2011-09-15 15:36:57.000000000 -0700
+++ Intel/topology.c	2011-09-15 15:37:10.000000000 -0700
@@ -20,6 +20,7 @@
  * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
  */
 
+#ifndef __FreeBSD__	/* FreeBSD has fls() in strings.h */
 static int fls(int x)
 {
 	int r = 32;
@@ -48,6 +49,7 @@
 	}
 	return r;
 }
+#endif
 
 static int get_count_order(unsigned int count)
 {
