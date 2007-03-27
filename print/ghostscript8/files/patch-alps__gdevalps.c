--- alps/gdevalps.c.orig	Wed Nov 24 09:28:35 1999
+++ alps/gdevalps.c	Fri Dec 17 19:12:35 2004
@@ -173,7 +173,7 @@
 {
   int lnum;
   int line_size = gdev_mem_bytes_per_scan_line((gx_device *)pdev);
-  byte *data = (byte *)gs_malloc(8, line_size, "md50_print_page(data)" );
+  byte *data = (byte *)gs_malloc(pdev->memory, 8, line_size, "md50_print_page(data)" );
   int skipping = 0;
   int nbyte;
   int nskip;
@@ -232,8 +232,8 @@
 {
   int lnum;
   int line_size = gdev_mem_bytes_per_scan_line((gx_device *)pdev);
-  byte *data = (byte *)gs_malloc(8, line_size, "md1xm_print_page(data)");
-  byte *out_start = (byte *)gs_malloc(8, line_size, "md1xm_print_page(data)");
+  byte *data = (byte *)gs_malloc(pdev->memory, 8, line_size, "md1xm_print_page(data)");
+  byte *out_start = (byte *)gs_malloc(pdev->memory, 8, line_size, "md1xm_print_page(data)");
   int skipping = 0;
   int nbyte;
 
