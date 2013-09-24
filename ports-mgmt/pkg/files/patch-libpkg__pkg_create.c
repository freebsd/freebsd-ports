--- ./libpkg/pkg_create.c.orig	2013-09-24 16:27:05.716245523 -0500
+++ ./libpkg/pkg_create.c	2013-09-24 16:27:17.642245427 -0500
@@ -323,7 +323,7 @@
 		goto cleanup;
 	}
 
-	if (pkg_files(pkg, &file) != EPKG_OK &&
+	if (0 && pkg_files(pkg, &file) != EPKG_OK &&
 	    pkg_dirs(pkg, &dir) != EPKG_OK) {
 		/* Now traverse the file directories, adding to the archive */
 		packing_append_tree(pkg_archive, md_dir, NULL);
