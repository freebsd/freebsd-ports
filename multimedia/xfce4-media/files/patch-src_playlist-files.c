--- src/playlist-files.c.orig	2006-11-26 23:21:23.000000000 -0800
+++ src/playlist-files.c	2011-11-04 12:28:14.000000000 -0700
@@ -815,3 +815,3 @@
     
-    md5sum = exo_str_get_md5_str(original_uri);
+    md5sum = g_compute_checksum_for_string(G_CHECKSUM_MD5, original_uri, -1);
     
@@ -843,3 +843,3 @@
     
-    md5sum = exo_str_get_md5_str(original_uri);
+    md5sum = g_compute_checksum_for_string(G_CHECKSUM_MD5, original_uri, -1);
     
