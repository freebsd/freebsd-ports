--- config.m4.orig	2023-06-06 15:54:29 UTC
+++ config.m4
@@ -4,6 +4,9 @@ PHP_ARG_ENABLE([fileinfo],
     [Disable fileinfo support])],
   [yes])
 
+PHP_ARG_WITH(pcre-dir, pcre install prefix,
+[  --with-pcre-dir           FILEINFO: pcre install prefix], no, no)
+
 if test "$PHP_FILEINFO" != "no"; then
 
   libmagic_sources=" \
@@ -48,6 +51,8 @@ int main(void)
     AC_MSG_NOTICE(using libmagic strcasestr implementation)
     libmagic_sources="$libmagic_sources libmagic/strcasestr.c"
   ],[AC_MSG_RESULT([skipped, cross-compiling])])
+
+  PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
 
   PHP_NEW_EXTENSION(fileinfo, fileinfo.c php_libmagic.c $libmagic_sources, $ext_shared,,-I@ext_srcdir@/libmagic)
   PHP_ADD_BUILD_DIR($ext_builddir/libmagic)
