--- panel-plugin/memswap.c.orig	2007-01-18 02:01:09.000000000 +0800
+++ panel-plugin/memswap.c	2008-03-03 21:01:50.000000000 +0800
@@ -203,7 +203,7 @@
 gint read_memswap(gulong *mem, gulong *swap, gulong *MT, gulong *MU, gulong *ST, gulong *SU)
 {
     int total_pages;
-    int free_pages;
+    u_int free_pages;
     int inactive_pages;
     int pagesize = getpagesize();
     int swap_avail;
@@ -222,8 +222,8 @@
         return -1;
     }
 
-    *MT = (total_pages*pagesize) >> 10;
-    *MU = ((total_pages-free_pages-inactive_pages) * pagesize) >> 10;
+    *MT = CONVERT(total_pages);
+    *MU = CONVERT(total_pages-free_pages-inactive_pages);
     *mem = *MU * 100 / *MT;
 
     if((*swap = swapmode(&swap_avail, &swap_free)) >= 0) {


