--- ext/domxml/config.m4.orig	Wed Dec 19 18:40:15 2001
+++ ext/domxml/config.m4	Wed Dec 19 18:42:15 2001
@@ -53,6 +53,8 @@
 
   PHP_ADD_LIBRARY_WITH_PATH($DOM_LIBNAME, $DOMXML_DIR/lib, DOMXML_SHARED_LIBADD)
   PHP_ADD_INCLUDE($DOMXML_DIR/include$DOMXML_DIR_ADD)
+dnl next line is for iconv.h
+  PHP_ADD_INCLUDE($DOMXML_DIR/include)
 
   if test "$PHP_ZLIB_DIR" = "no"; then
     AC_MSG_ERROR(DOMXML requires ZLIB. Use --with-zlib-dir=<DIR>)
