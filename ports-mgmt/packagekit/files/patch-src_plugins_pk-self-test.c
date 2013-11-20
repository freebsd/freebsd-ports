--- src/plugins/pk-self-test.c.orig	2013-06-06 16:35:45.000000000 +0000
+++ src/plugins/pk-self-test.c	2013-06-06 16:37:24.000000000 +0000
@@ -67,6 +67,7 @@
 	pk_test_lsof_get_files_for_directory (files, "/usr/lib64");
 	pk_test_lsof_get_files_for_directory (files, "/usr/lib/x86_64-linux-gnu");
 	pk_test_lsof_get_files_for_directory (files, "/usr/lib/i386-linux-gnu");
+	pk_test_lsof_get_files_for_directory (files, "/usr/local/lib");
 	g_assert_cmpint (files->len, >, 0);
 	g_ptr_array_add (files, NULL);
 	pids = pk_lsof_get_pids_for_filenames (lsof, (gchar**) files->pdata);
