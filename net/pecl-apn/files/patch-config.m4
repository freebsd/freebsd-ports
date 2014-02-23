--- ./config.m4.orig	2014-02-20 16:43:19.000000000 +0800
+++ ./config.m4	2014-02-21 09:06:40.000000000 +0800
@@ -37,16 +37,16 @@
       AC_MSG_ERROR([libcapn is not found. Please visit to http://www.libcapn.org/php-apn for more information])
     fi
 
-    APN_INCDIR=$APN_DIR/include/capn
+    APN_INCDIR=$APN_DIR/include
 
     SEARCH_LIBS_PATH="/usr/local/lib /usr/lib /usr/lib64 /usr/local/lib64"
     SEARCH_LIB_FILE=libcapn.$SHLIB_SUFFIX_NAME
-    if test -r $PHP_APN/capn/$SEARCH_LIB_FILE; then
+    if test -r $PHP_APN/$SEARCH_LIB_FILE; then
         APN_LIBDIR=$PHP_APN
     else
       AC_MSG_CHECKING([for $SEARCH_LIB_FILE in default path])
       for i in $SEARCH_LIBS_PATH; do
-        if test -r $i/capn/$SEARCH_LIB_FILE; then
+        if test -r $i/$SEARCH_LIB_FILE; then
            APN_LIBDIR=$i
            AC_MSG_RESULT(found in $i)
            break
@@ -59,7 +59,7 @@
       AC_MSG_ERROR([libcapn is not found. Please visit to http://www.libcapn.org/php-apn for more information])
     fi
 
-    APN_LIBDIR=$APN_LIBDIR/capn
+    APN_LIBDIR=$APN_LIBDIR
 
     PHP_ADD_INCLUDE($APN_INCDIR)
     PHP_ADD_LIBRARY_WITH_PATH(capn, $APN_LIBDIR, APN_SHARED_LIBADD)
