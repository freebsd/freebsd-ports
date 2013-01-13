--- ./libpkg/pkg_repo.c.orig	2012-12-21 05:57:15.000000000 -0600
+++ ./libpkg/pkg_repo.c	2013-01-13 12:16:18.126457634 -0600
@@ -520,7 +520,7 @@
 maybe_delete_conflicting(const char *origin, const char *version,
 			 const char *pkg_path)
 {
-	int ret;
+	int ret = EPKG_FATAL;
 	const char *oversion;
 
 	if (run_prepared_statement(VERSION, origin) != SQLITE_ROW)
