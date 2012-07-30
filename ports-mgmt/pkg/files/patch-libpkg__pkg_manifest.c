--- ./libpkg/pkg_manifest.c.orig	2012-07-30 01:08:44.000000000 +0200
+++ ./libpkg/pkg_manifest.c	2012-07-30 10:23:20.768918130 +0200
@@ -189,8 +189,7 @@
 {
 	int ret = EPKG_OK;
 
-	while (val->data.scalar.length > 1 &&
-	    val->data.scalar.value[val->data.scalar.length - 2] == '\n' &&
+	while (val->data.scalar.length > 0 &&
 	    val->data.scalar.value[val->data.scalar.length - 1] == '\n') {
 		val->data.scalar.value[val->data.scalar.length - 1] = '\0';
 		val->data.scalar.length--;
