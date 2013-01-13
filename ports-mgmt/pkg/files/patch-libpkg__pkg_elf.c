--- ./libpkg/pkg_elf.c.orig	2012-12-21 05:57:15.000000000 -0600
+++ ./libpkg/pkg_elf.c	2013-01-13 12:16:18.123459813 -0600
@@ -195,8 +195,8 @@
 	struct stat sb;
 	int ret = EPKG_OK;
 
-	size_t numdyn;
-	size_t sh_link;
+	size_t numdyn = 0;
+	size_t sh_link = 0;
 	size_t dynidx;
 	const char *osname;
 
