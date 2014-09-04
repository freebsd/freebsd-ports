--- config.m4.orig	2010-09-07 15:45:30.000000000 +0200
+++ config.m4	2010-09-07 15:46:50.000000000 +0200
@@ -4,6 +4,9 @@
 PHP_ARG_ENABLE(fileinfo, for fileinfo support,
 [  --disable-fileinfo      Disable fileinfo support], yes)
 
+PHP_ARG_WITH(pcre-dir, pcre install prefix,
+[  --with-pcre-dir           FILEINFO: pcre install prefix], no, no)
+
 if test "$PHP_FILEINFO" != "no"; then
 
   libmagic_sources=" \
@@ -13,6 +16,8 @@
     libmagic/is_tar.c libmagic/magic.c libmagic/print.c \
     libmagic/readcdf.c libmagic/readelf.c libmagic/softmagic.c"
 
+  PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
+
   PHP_NEW_EXTENSION(fileinfo, fileinfo.c $libmagic_sources, $ext_shared,,-I@ext_srcdir@/libmagic)
   PHP_ADD_BUILD_DIR($ext_builddir/libmagic)
 
