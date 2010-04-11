--- ./report.c.orig	2010-04-09 00:36:30.000000000 +0200
+++ ./report.c	2010-04-11 19:05:39.000000000 +0200
@@ -741,7 +741,7 @@
 static void copy_static_code(u8* out_dir) {
   struct dirent** d;
   ca_out_dir = out_dir;
-  scandir(ASSETS_DIR, &d, copy_asset, NULL);
+  scandir(ASSETS_DIR, &d, (int(*)())copy_asset, NULL);
 }
 
 
