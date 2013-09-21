--- ./pkg/register.c.orig	2013-09-19 20:56:18.299519000 +0200
+++ ./pkg/register.c	2013-09-19 20:56:34.568231772 +0200
@@ -285,7 +285,7 @@
 	 */
 
 	if (!testing_mode)
-		pkg_analyse_files(db, pkg);
+		pkg_analyse_files(db, pkg, input_path);
 
 	pkg_get(pkg, PKG_ARCH, &arch);
 	if (arch == NULL) {
