--- config.m4.orig	Fri Jun 25 16:26:35 2004
+++ config.m4	Fri Jun 25 16:27:13 2004
@@ -30,6 +30,7 @@
   PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
   [
     PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PANDA_DIR/lib, PANDA_SHARED_LIBADD)
+    PHP_ADD_INCLUDE($PANDA_DIR/include)
     AC_DEFINE(HAVE_PANDALIB,1,[ ])
   ],[
     AC_MSG_ERROR([wrong panda lib version or lib not found])
