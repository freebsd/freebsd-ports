--- src/gxobj.h.orig	Tue Mar 14 01:18:19 2006
+++ src/gxobj.h	Fri Mar 23 14:41:44 2007
@@ -109,11 +109,15 @@
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
