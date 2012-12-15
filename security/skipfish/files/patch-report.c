--- ./src/report.c.orig	2012-09-24 11:55:23.000000000 -0400
+++ ./src/report.c	2012-09-24 11:55:32.000000000 -0400
@@ -799,7 +799,7 @@
 static void copy_static_code(u8* out_dir) {
   struct dirent** d;
   ca_out_dir = out_dir;
-  scandir(ASSETS_DIR, &d, copy_asset, NULL);
+  scandir(ASSETS_DIR, &d, (int(*)())copy_asset, NULL);
 }
 
 
