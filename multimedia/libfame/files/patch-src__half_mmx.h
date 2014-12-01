--- src/half_mmx.h.orig	2002-04-30 22:04:02.000000000 +0400
+++ src/half_mmx.h	2014-12-01 01:08:04.000000000 +0300
@@ -18,7 +18,7 @@
 */
 /**************************** half-pixel interpolation ***********************/
 
-static short const _mmx_one[] = { 1, 1, 1, 1 };
+short const _mmx_one[] = { 1, 1, 1, 1 };
 
 static void inline mmx_interpolate(unsigned char **ref,
 				   int pitch,
