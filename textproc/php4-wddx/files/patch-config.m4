--- config.m4.orig	Mon Jul 26 09:05:10 2004
+++ config.m4	Mon Jul 26 09:07:46 2004
@@ -5,6 +5,9 @@
 PHP_ARG_ENABLE(wddx,whether to enable WDDX support,
 [  --enable-wddx           Enable WDDX support.])
 
+PHP_ARG_WITH(expat-dir, external libexpat install dir,
+[  --with-expat-dir=<DIR>    WDDX: external libexpat install dir], no, no)
+
 if test "$PHP_WDDX" != "no"; then
   if test "$ext_shared" != "yes" && test "$enable_xml" = "no"; then
     AC_MSG_WARN(Activating XML)
@@ -12,4 +15,18 @@
   fi
   AC_DEFINE(HAVE_WDDX, 1, [ ])
   PHP_NEW_EXTENSION(wddx, wddx.c, $ext_shared)
+
+  for i in $PHP_EXPAT_DIR; do
+    if test -f $i/lib/libexpat.a -o -f $i/lib/libexpat.$SHLIB_SUFFIX_NAME ; then
+      EXPAT_DIR=$i
+    fi
+  done
+
+  if test -z "$EXPAT_DIR"; then
+    AC_MSG_ERROR(not found. Please reinstall the expat distribution.)
+  fi
+
+  PHP_ADD_INCLUDE($EXPAT_DIR/include)
+  PHP_ADD_LIBRARY_WITH_PATH(expat, $EXPAT_DIR/lib, XML_SHARED_LIBADD)
+  PHP_SUBST(XML_SHARED_LIBADD)
 fi
