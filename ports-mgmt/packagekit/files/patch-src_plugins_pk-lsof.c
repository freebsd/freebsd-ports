--- src/plugins/pk-lsof.c.orig	2013-04-11 11:58:36.000000000 +0000
+++ src/plugins/pk-lsof.c	2013-06-07 09:40:48.000000000 +0000
@@ -181,10 +181,10 @@ pk_lsof_refresh (PkLsof *lsof)
 	g_return_val_if_fail (PK_IS_LSOF (lsof), FALSE);
 
 	/* try to find lsof */
-	lsof_name = "/usr/sbin/lsof";
+	lsof_name = "%%LOCALBASE%%/sbin/lsof";
 	ret = g_file_test (lsof_name, G_FILE_TEST_EXISTS);
 	if (!ret) {
-		lsof_name = "/usr/bin/lsof";
+		lsof_name = "%%LOCALBASE%%/bin/lsof";
 		ret = g_file_test (lsof_name, G_FILE_TEST_EXISTS);
 		if (!ret) {
 			g_warning ("lsof not found, cannot continue");
