--- src/gxobj.h.orig	Fri Feb 22 07:24:53 2002
+++ src/gxobj.h	Fri Dec 20 22:56:03 2002
@@ -103,10 +103,14 @@
  * required by the hardware, regardless of the value of obj_align_mod.
  * See gsmemraw.h for more information about this.
  */
+#if !defined(__ia64__)
 #define obj_align_mod\
   (((arch_align_memory_mod - 1) |\
     (align_bitmap_mod - 1) |\
     (obj_back_scale - 1)) + 1)
+#else
+#define obj_align_mod 16
+#endif
 /* The only possible values for obj_align_mod are 4, 8, or 16.... */
 #if obj_align_mod == 4
 #  define log2_obj_align_mod 2
