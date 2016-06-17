--- src/gxobj.h.orig	2003-01-17 00:49:04 UTC
+++ src/gxobj.h
@@ -101,10 +101,14 @@ typedef struct obj_header_data_s {
  * The final | is because back pointer values are divided by obj_back_scale,
  * so objects must be aligned at least 0 mod obj_back_scale.
  */
+#if !defined(__ia64__) && !defined(__amd64__)
 #define obj_align_mod\
   (((arch_align_long_mod - 1) | (arch_align_ptr_mod - 1) |\
     (arch_align_double_mod - 1) | (align_bitmap_mod - 1) |\
     (obj_back_scale - 1)) + 1)
+#else
+#define obj_align_mod	16
+#endif
 /* The only possible values for obj_align_mod are 4, 8, or 16.... */
 #if obj_align_mod == 4
 #  define log2_obj_align_mod 2
