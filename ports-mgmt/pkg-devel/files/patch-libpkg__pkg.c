--- libpkg/pkg.c.orig	2013-07-06 12:48:19.000000000 +0200
+++ libpkg/pkg.c	2013-10-05 19:45:16.675062417 +0200
@@ -1181,6 +1181,20 @@
 	struct pkg_dir *dir = NULL;
 	char spath[MAXPATHLEN + 1];
 	char dpath[MAXPATHLEN + 1];
+	bool disable_mtree;
+	const char *prefix;
+	char *mtree;
+
+	pkg_config_bool(PKG_CONFIG_DISABLE_MTREE, &disable_mtree);
+	if (!disable_mtree) {
+		pkg_get(pkg, PKG_PREFIX, &prefix, PKG_MTREE, &mtree);
+		do_extract_mtree(mtree, prefix);
+	}
+
+	/*
+	 * Execute pre-install scripts
+	 */
+	pkg_script_run(pkg, PKG_SCRIPT_PRE_INSTALL);
 
 	if (packing_init(&pack, dest, 0) != EPKG_OK) {
 		/* TODO */
@@ -1190,15 +1204,21 @@
 	while (pkg_dirs(pkg, &dir) == EPKG_OK) {
 		snprintf(spath, sizeof(spath), "%s%s", src, pkg_dir_path(dir));
 		snprintf(dpath, sizeof(dpath), "%s%s", dest, pkg_dir_path(dir));
-		packing_append_file(pack, spath, dpath);
+		packing_append_file_attr(pack, spath, dpath,
+		    dir->uname, dir->gname, dir->perm);
 	}
 
 	while (pkg_files(pkg, &file) == EPKG_OK) {
 		snprintf(spath, sizeof(spath), "%s%s", src, pkg_file_path(file));
 		snprintf(dpath, sizeof(dpath), "%s%s", dest, pkg_file_path(file));
-		packing_append_file(pack, spath, dpath);
+		packing_append_file_attr(pack, spath, dpath,
+		    file->uname, file->gname, file->perm);
 	}
 
+	/*
+	 * Execute post install scripts
+	 */
+	pkg_script_run(pkg, PKG_SCRIPT_POST_INSTALL);
 
 	return (packing_finish(pack));
 }
