--- lips/gdevlprn.h.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevlprn.h	Sun Nov 10 21:11:22 2002
@@ -29,7 +29,7 @@
 #include "gdevprn.h"
 
 #define lprn_dev_proc_image_out(proc)\
-  void proc(P6(gx_device_printer *, FILE *, int, int, int, int))
+  void proc(gx_device_printer *, FILE *, int, int, int, int)
 
 #define dev_proc_image_out(proc) lprn_dev_proc_image_out(proc)
 
