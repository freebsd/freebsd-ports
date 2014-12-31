--- config.m4.orig	2011-11-15 01:13:43 UTC
+++ config.m4
@@ -7,13 +7,9 @@ if test -z "$PHP_LIBCLD_DIR"; then
 fi
 
 if test "$PHP_CLD" != "no"; then
-    if ! test -f $PHP_LIBCLD_DIR/libcld.a; then
-        AC_MSG_ERROR([libcld not found. Specify installation directory with --with-libcld-dir=])
-    fi
-
     PHP_REQUIRE_CXX()
     PHP_SUBST(CLD_SHARED_LIBADD)
-    PHP_ADD_INCLUDE($PHP_LIBCLD_DIR)
+    PHP_ADD_INCLUDE([/usr/local/include/cld])
     PHP_ADD_LIBRARY(stdc++, 1, CLD_SHARED_LIBADD)
     PHP_ADD_LIBRARY_WITH_PATH(cld, $PHP_LIBCLD_DIR, CLD_SHARED_LIBADD)
     PHP_NEW_EXTENSION(cld, cld.cc, $ext_shared)
