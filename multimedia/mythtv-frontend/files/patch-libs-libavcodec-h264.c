--- libs/libavcodec/h264.c.orig	2008-11-02 21:53:29.000000000 +0100
+++ libs/libavcodec/h264.c	2008-11-02 21:54:24.000000000 +0100
@@ -5366,7 +5366,7 @@
     return ctx + 4 * cat;
 }
 
-static const attribute_used uint8_t last_coeff_flag_offset_8x8[63] = {
+const attribute_used uint8_t last_coeff_flag_offset_8x8[63] = {
     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
