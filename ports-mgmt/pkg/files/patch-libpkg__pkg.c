--- ./libpkg/pkg.c.orig	2013-09-24 14:53:00.000000000 +0200
+++ ./libpkg/pkg.c	2013-09-24 14:58:33.000000000 +0200
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
@@ -1200,6 +1214,11 @@
 	}
 
 
+	/*
+	 * Execute post install scripts
+	 */
+	pkg_script_run(pkg, PKG_SCRIPT_POST_INSTALL);
+
 	return (packing_finish(pack));
 }
 
