--- config.m4.orig	Thu Aug 26 09:44:58 2004
+++ config.m4	Thu Aug 26 09:47:37 2004
@@ -66,6 +66,7 @@
   fi
 
   PHP_ADD_INCLUDE($DOMXML_DIR/include$DOMXML_DIR_ADD)
+  PHP_ADD_INCLUDE($DOMXML_DIR/include)
 
   if test "$PHP_ZLIB_DIR" = "no"; then
     AC_MSG_ERROR(DOMXML requires ZLIB. Use --with-zlib-dir=<DIR>)
