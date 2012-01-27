--- ./agent/mibgroup/hardware/fsys/hw_fsys.c.orig	2012-01-27 09:59:29.000000000 -0500
+++ ./agent/mibgroup/hardware/fsys/hw_fsys.c	2012-01-27 09:59:38.000000000 -0500
@@ -334,6 +334,6 @@
 
     f->size_32 = s;
     f->units_32 = u;
-    f->avail_32 = f->avail << factor;
-    f->used_32 = f->used << factor;
+    f->avail_32 = f->avail >> factor;
+    f->used_32 = f->used >> factor;
 }
