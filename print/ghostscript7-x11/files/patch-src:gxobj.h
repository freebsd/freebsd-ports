--- src/gxobj.h.orig	Fri Feb 22 19:45:59 2002
+++ src/gxobj.h	Thu Dec 19 00:16:57 2002
@@ -99,10 +99,14 @@
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
