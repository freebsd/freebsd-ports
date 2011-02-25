--- src/radeon_driver.c.orig	2010-12-03 20:34:44.419175412 +1000
+++ src/radeon_driver.c	2010-12-03 20:37:22.896179333 +1000
@@ -1454,6 +1454,9 @@
      * internal memory map.
      * See fdo bug 24301.
      */
+    if (mem_size > aper_size)
+	mem_size = aper_size;
+
     if (mem_size > 0x20000000)
 	mem_size = aper_size;
 
