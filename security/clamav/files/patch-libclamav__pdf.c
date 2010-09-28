--- libclamav/pdf.c.orig	2010-09-28 14:19:25.000000000 -0300
+++ libclamav/pdf.c	2010-09-28 14:19:49.000000000 -0300
@@ -1024,7 +1024,7 @@
     offset += pdfver - start;
 
     /* find trailer and xref, don't fail if not found */
-    map_off = map->len - 2048;
+    map_off = (off_t)map->len - 2048;
     if (map_off < 0)
 	map_off = 0;
     bytesleft = map->len - map_off;
