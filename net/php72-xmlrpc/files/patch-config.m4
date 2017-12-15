--- config.m4.orig	2014-04-29 08:04:30.000000000 +0000
+++ config.m4	2014-05-15 08:04:00.883004682 +0000
@@ -61,11 +61,9 @@ if test "$PHP_XMLRPC" != "no"; then
     fi
   fi
 
-  dnl if iconv is shared or missing then we should build iconv ourselves
-  if test "$PHP_ICONV_SHARED" = "yes" || test "$PHP_ICONV" = "no"; then
-
     if test "$PHP_ICONV_DIR" != "no"; then
       PHP_ICONV=$PHP_ICONV_DIR
+      PHP_ADD_INCLUDE($PHP_ICONV_DIR/include)
     fi
   
     if test -z "$PHP_ICONV" || test "$PHP_ICONV" = "no"; then
@@ -75,7 +73,6 @@ if test "$PHP_XMLRPC" != "no"; then
     PHP_SETUP_ICONV(XMLRPC_SHARED_LIBADD, [], [
       AC_MSG_ERROR([iconv not found, in order to build xmlrpc you need the iconv library])
     ])
-  fi
 fi
 
 if test "$PHP_XMLRPC" = "yes"; then
