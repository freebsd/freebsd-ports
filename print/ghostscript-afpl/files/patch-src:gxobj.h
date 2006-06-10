--- src/gxobj.h.orig	Tue Mar 14 01:18:19 2006
+++ src/gxobj.h	Sat May 27 14:48:20 2006
@@ -109,10 +109,14 @@
  * required by the hardware, regardless of the value of obj_align_mod.
  * See gsmemraw.h for more information about this.
  */
+#if !defined(__ia64__) && !defined(__amd64__)
 #define obj_align_mod\
   (((ARCH_ALIGN_MEMORY_MOD - 1) |\
     (align_bitmap_mod - 1) |\
     (obj_back_scale - 1)) + 1)
+#else
+#define obj_align_mod  16
+#endif
 /* The only possible values for obj_align_mod are 4, 8, or 16.... */
 #if obj_align_mod == 4
 #  define log2_obj_align_mod 2
