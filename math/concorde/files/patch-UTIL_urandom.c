
$FreeBSD$

--- UTIL/urandom.c.orig	Thu Dec 16 19:39:06 1999
+++ UTIL/urandom.c	Tue Nov 12 17:10:02 2002
@@ -22,7 +22,7 @@
 /*                                                                          */
 /*  Written by:  DIMACS  (modified for TSP)                                 */
 /*  Date: February 7, 1995  (cofeb16)                                       */
-/*                                                                          */
+/*        September 18, 2001  (billenium fix)                               */
 /*                                                                          */
 /*    EXPORTED FUNCTIONS:                                                   */
 /*                                                                          */
@@ -66,6 +66,9 @@
     int i, ii;
     int last, next;
     int *arr = r->arr;
+
+    seed %= CC_PRANDMAX;
+    if (seed < 0) seed += CC_PRANDMAX;
 
     arr[0] = last = seed;
     next = 1;
