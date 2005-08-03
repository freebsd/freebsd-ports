--- src/sfnt/sfdriver.c.orig	Wed Aug  3 18:46:34 2005
+++ src/sfnt/sfdriver.c	Wed Aug  3 18:47:24 2005
@@ -367,8 +367,13 @@
     /* see `ttsbit.h' and `sfnt.h' */
     tt_face_set_sbit_strike,
     tt_face_load_sbit_strikes,
-    0 /* tt_find_sbit_image */,
-    0 /* tt_load_sbit_metrics */,
+#ifdef FT_OPTIMIZE_MEMORY
+    0,
+    0,
+#else
+    tt_find_sbit_image,
+    tt_load_sbit_metrics,
+#endif
     tt_face_load_sbit_image,
     tt_face_free_sbit_strikes,
 
