--- src/gxobj.h.orig	Thu Feb 21 14:24:53 2002
+++ src/gxobj.h	Sat Sep 27 19:17:17 2003
@@ -103,11 +103,15 @@
  * required by the hardware, regardless of the value of obj_align_mod.
  * See gsmemraw.h for more information about this.
  */
+#if !defined(__ia64__) && !defined(__amd64__)
 #define obj_align_mod\
   (((arch_align_memory_mod - 1) |\
     (align_bitmap_mod - 1) |\
     (obj_back_scale - 1)) + 1)
 /* The only possible values for obj_align_mod are 4, 8, or 16.... */
+#else
+#define obj_align_mod  16
+#endif
 #if obj_align_mod == 4
 #  define log2_obj_align_mod 2
 #else
