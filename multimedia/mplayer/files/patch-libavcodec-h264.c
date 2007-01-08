--- libavcodec/h264.c.orig	Thu Dec 21 14:57:54 2006
+++ libavcodec/h264.c	Thu Dec 21 15:00:14 2006
@@ -6034,7 +6034,7 @@
     return ctx + 4 * cat;
 }
 
-static const __attribute((used)) uint8_t last_coeff_flag_offset_8x8[63] = {
+const __attribute((used)) uint8_t last_coeff_flag_offset_8x8[63] = {
     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
