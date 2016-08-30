--- config.m4.orig	2016-03-30 13:42:31 UTC
+++ config.m4
@@ -81,7 +81,7 @@ if test "$PHP_SOLR" != "no"; then
     
     PHP_ADD_INCLUDE($CURL_DIR/include)
     PHP_EVAL_LIBLINE($CURL_LIBS, SOLR_SHARED_LIBADD)
-    PHP_ADD_LIBRARY_WITH_PATH(curl, $CURL_DIR/lib, SOLR_SHARED_LIBADD)
+    PHP_ADD_LIBRARY_WITH_PATH(curl, $CURL_DIR/$PHP_LIBDIR, SOLR_SHARED_LIBADD)
   
 	if test "$PHP_LIBXML" = "no"; then   
         AC_MSG_ERROR([Solr extension requires LIBXML extension, add --enable-libxml])                
