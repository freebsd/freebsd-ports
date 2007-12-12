--- libavcodec/h264.c.orig	2007-10-08 03:49:36.000000000 +0800
+++ libavcodec/h264.c	2007-10-20 16:03:23.000000000 +0800
@@ -5241,7 +5241,7 @@
     return ctx + 4 * cat;
 }
 
-static const attribute_used uint8_t last_coeff_flag_offset_8x8[63] = {
+const attribute_used uint8_t last_coeff_flag_offset_8x8[63] = {
     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
