--- config.m4.orig	2014-05-15 08:00:57.801291749 +0000
+++ config.m4	2014-05-15 08:01:40.161014307 +0000
@@ -61,11 +61,9 @@
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
@@ -75,7 +73,6 @@
     PHP_SETUP_ICONV(XMLRPC_SHARED_LIBADD, [], [
       AC_MSG_ERROR([iconv not found, in order to build xmlrpc you need the iconv library])
     ])
-  fi
 fi
 
 if test "$PHP_XMLRPC" = "yes"; then
