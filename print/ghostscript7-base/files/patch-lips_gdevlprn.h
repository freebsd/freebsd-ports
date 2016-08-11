--- lips/gdevlprn.h.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevlprn.h	Sat Sep 13 23:06:38 2003
@@ -28,8 +28,13 @@
 
 #include "gdevprn.h"
 
+#if GS_VERSION_MAJOR >= 8
+#define lprn_dev_proc_image_out(proc)\
+  void proc(gx_device_printer *, FILE *, int, int, int, int)
+#else
 #define lprn_dev_proc_image_out(proc)\
   void proc(P6(gx_device_printer *, FILE *, int, int, int, int))
+#endif
 
 #define dev_proc_image_out(proc) lprn_dev_proc_image_out(proc)
 
