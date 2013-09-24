--- ./libpkg/private/pkg.h.orig	2013-09-24 14:56:39.000000000 +0200
+++ ./libpkg/private/pkg.h	2013-09-24 14:57:23.000000000 +0200
@@ -405,4 +405,5 @@
 int pkg_emit_filelist(struct pkg *, FILE *);
 int pkg_parse_manifest_archive(struct pkg *pkg, struct archive *a, struct pkg_manifest_key *keys);
 
+int do_extract_mtree(char *mtree, const char *prefix);
 #endif
