--- ext/domxml/config.m4.orig	Sun May 27 11:37:40 2001
+++ ext/domxml/config.m4	Sun Nov 18 23:20:57 2001
@@ -3,7 +3,7 @@
 
 AC_DEFUN(PHP_DOM_CHECK_VERSION,[
   old_CPPFLAGS=$CPPFLAGS
-  CPPFLAGS=-I$DOMXML_DIR/include
+  CPPFLAGS=-I$DOMXML_DIR/include/libxml2
   AC_MSG_CHECKING(for libxml version)
   AC_EGREP_CPP(yes,[
   #include <libxml/xmlversion.h>
@@ -25,7 +25,7 @@
 
 if test "$PHP_DOM" != "no"; then
 
-  if test -r $PHP_DOM/include/libxml/tree.h; then
+  if test -r $PHP_DOM/include/libxml2/libxml/tree.h; then
     DOMXML_DIR=$PHP_DOM
   else
     AC_MSG_CHECKING(for DOM in default path)
@@ -44,6 +44,8 @@
 
   PHP_DOM_CHECK_VERSION
 
+  PHP_ADD_INCLUDE($DOMXML_DIR/include/libxml2)
+dnl next line is for giconv.h
   PHP_ADD_INCLUDE($DOMXML_DIR/include)
 
   if test -f $DOMXML_DIR/lib/libxml2.a -o -f $DOMXML_DIR/lib/libxml2.s? ; then
