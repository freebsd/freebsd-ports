--- ot_accesslist.c.orig	2010-11-04 17:34:00.000000000 -0700
+++ ot_accesslist.c	2010-11-04 17:51:33.000000000 -0700
@@ -54,8 +54,7 @@
     return;
   }
 
-  /* No use to scan if there's not enough room for another full info_hash */
-  map_end = map + maplen - 40;
+  map_end = map + maplen;
   read_offs = map;
 
   /* We do ignore anything that is not of the form "^[:xdigit:]{40}[^:xdigit:].*" */
