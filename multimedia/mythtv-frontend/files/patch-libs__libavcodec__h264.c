--- ./libs/libavcodec/h264.c.orig	2008-03-04 16:05:31.000000000 -0500
+++ ./libs/libavcodec/h264.c	2009-04-22 21:05:20.000000000 -0400
@@ -5366,7 +5366,7 @@
     return ctx + 4 * cat;
 }
 
-static const attribute_used uint8_t last_coeff_flag_offset_8x8[63] = {
+const attribute_used uint8_t last_coeff_flag_offset_8x8[63] = {
     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
