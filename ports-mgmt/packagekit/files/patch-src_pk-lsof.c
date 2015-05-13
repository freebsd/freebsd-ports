--- src/pk-lsof.c.orig	2010-10-21 18:50:10.000000000 +0200
+++ src/pk-lsof.c	2010-11-27 14:39:56.000000000 +0100
@@ -154,7 +154,7 @@
 	g_return_val_if_fail (PK_IS_LSOF (lsof), FALSE);
 
 	/* try to find lsof */
-	lsof_name = "/usr/sbin/lsof";
+	lsof_name = "%%LOCALBASE%%/sbin/lsof";
 	ret = g_file_test (lsof_name, G_FILE_TEST_EXISTS);
 	if (!ret) {
 		lsof_name = "/usr/bin/lsof";
