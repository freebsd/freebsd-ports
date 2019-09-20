--- config.m4.orig	2017-11-03 18:32:08 UTC
+++ config.m4
@@ -50,14 +50,6 @@ if test "$PHP_SODIUM" != "no"; then
     PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIBSODIUM_DIR/$PHP_LIBDIR, SODIUM_SHARED_LIBADD)
   fi
 
-  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
-  [
-    AC_DEFINE(HAVE_LIBSODIUMLIB,1,[ ])
-  ],[
-    AC_MSG_ERROR([wrong libsodium lib version (< 1.0.8) or lib not found])
-  ],[
-  ])
-
   PHP_SUBST(SODIUM_SHARED_LIBADD)
 
   PHP_NEW_EXTENSION(sodium, libsodium.c, $ext_shared)
