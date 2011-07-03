--- ./panel-plugin/memswap.c.orig	2010-12-09 19:04:10.000000000 +0300
+++ ./panel-plugin/memswap.c	2011-07-03 15:39:52.384882846 +0400
@@ -228,8 +228,8 @@
         return -1;
     }
 
-    *MT = (total_pages*pagesize) >> 10;
-    *MU = ((total_pages-free_pages-inactive_pages) * pagesize) >> 10;
+    *MT = CONVERT(total_pages);
+    *MU = CONVERT(total_pages-free_pages-inactive_pages);
     *mem = *MU * 100 / *MT;
 
     if((*swap = swapmode(&swap_avail, &swap_free)) >= 0) {
