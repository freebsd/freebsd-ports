
$FreeBSD$

--- src/c_main.c.orig	Wed Dec 12 17:18:06 2001
+++ src/c_main.c	Fri Jan 18 22:40:01 2002
@@ -59,6 +59,7 @@
 	reset_registers();
 	cpu->prescribed_format = DEFAULT_DISPLAY_FORMAT;
 	cpu->angle_measure = DEFAULT_ANGLE_MEASURE;
+	cpu->curr_mem = 0;
 	/* slightly underestimated precision 
 	 * it is going to be used in evaluation of
 	 * trigonometric functions to get sin PI = 0 rather than 10^-17 */
