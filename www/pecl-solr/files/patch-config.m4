--- config.m4.orig	2014-06-22 18:58:51.253187297 +0800
+++ config.m4	2014-06-22 19:01:04.313188083 +0800
@@ -82,7 +82,7 @@
     
     PHP_ADD_INCLUDE($CURL_DIR/include)
     PHP_EVAL_LIBLINE($CURL_LIBS, SOLR_SHARED_LIBADD)
-    PHP_ADD_LIBRARY_WITH_PATH(curl, $CURL_DIR/lib, SOLR_SHARED_LIBADD)
+    PHP_ADD_LIBRARY_WITH_PATH(curl, $CURL_DIR/$PHP_LIBDIR, SOLR_SHARED_LIBADD)
   
 	if test "$PHP_LIBXML" = "no"; then   
         AC_MSG_ERROR([Solr extension requires LIBXML extension, add --enable-libxml])                
