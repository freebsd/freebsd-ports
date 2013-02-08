--- config.m4.orig	2011-11-29 10:49:53.000000000 +0800
+++ config.m4	2013-01-27 23:53:10.000000000 +0800
@@ -56,8 +56,8 @@ else
 fi
 
 PHP_ADD_INCLUDE($CURL_DIR/include)
-PHP_EVAL_LIBLINE($CURL_LIBS, CURL_SHARED_LIBADD)
-PHP_ADD_LIBRARY_WITH_PATH(curl, $CURL_DIR/$PHP_LIBDIR, CURL_SHARED_LIBADD)
+PHP_EVAL_LIBLINE($CURL_LIBS, SOLR_SHARED_LIBADD)
+PHP_ADD_LIBRARY_WITH_PATH(curl, $CURL_DIR/$PHP_LIBDIR, SOLR_SHARED_LIBADD)
 
 PHP_ARG_ENABLE(solr, whether to enable the Solr extension,
 [  --enable-solr         Enable solr support])
@@ -72,11 +72,11 @@ dnl Setting up the apache Solr extension
 if test "$PHP_SOLR" != "no"; then
 
 	if test "$PHP_CURL" = "no"; then   
-    	AC_MSG_ERROR([SOAP extension requires curl extension, add --with-curl])                
+    	AC_MSG_ERROR([SOLR extension requires curl extension, add --with-curl])                
 	fi
   
 	if test "$PHP_LIBXML" = "no"; then   
-    	AC_MSG_ERROR([SOAP extension requires LIBXML extension, add --enable-libxml])                
+    	AC_MSG_ERROR([SOLR extension requires LIBXML extension, add --enable-libxml])                
 	fi
 
 	PHP_SETUP_LIBXML(SOLR_SHARED_LIBADD, [
@@ -100,7 +100,7 @@ if test "$PHP_SOLR" != "no"; then
                              solr_functions_response.c \
     						 solr_functions_debug.c], 
     						 $ext_shared)
-    PHP_SUBST(SOAP_SHARED_LIBADD)
+    PHP_SUBST(SOLR_SHARED_LIBADD)
   ], [
     AC_MSG_ERROR([xml2-config not found. Please check your libxml2 installation.])
   ])
