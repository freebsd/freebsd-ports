--- base/gxobj.h.orig	2015-03-30 08:21:24 UTC
+++ base/gxobj.h
@@ -144,11 +144,15 @@ typedef struct obj_header_data_s {
  * required by the hardware, regardless of the value of obj_align_mod.
  * See gsmemraw.h for more information about this.
  */
+#if !defined(__ia64__) && !defined(__amd64__)
 #define obj_align_mod\
   (((ARCH_ALIGN_MEMORY_MOD - 1) |\
     (align_bitmap_mod - 1) |\
     (obj_back_scale - 1)) + 1)
 /* The only possible values for obj_align_mod are 4, 8, or 16.... */
+#else
+#define obj_align_mod  16
+#endif
 #if obj_align_mod == 4
 #  define log2_obj_align_mod 2
 #else
