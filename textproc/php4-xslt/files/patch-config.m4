--- config.m4.orig	Mon Jul 26 23:21:42 2004
+++ config.m4	Mon Jul 26 23:24:25 2004
@@ -146,7 +146,7 @@
     [
       AC_DEFINE(HAVE_SABLOT_SET_ENCODING, 1, [ ])
     ], [], [
-      -L$XSLT_DIR/lib $PHP_SABLOT_JS_LIBS
+      -L$XSLT_DIR/lib $PHP_SABLOT_JS_LIBS -lexpat -liconv
     ])
 
     dnl SablotSetOptions implemented in Sablotron CVS > 2002/10/31
@@ -154,7 +154,7 @@
     [
       AC_DEFINE(HAVE_SABLOT_GET_OPTIONS, 1, [Whether Sablotron supports SablotGetOptions])
     ], [], [
-      -L$XSLT_DIR/lib $PHP_SABLOT_JS_LIBS
+      -L$XSLT_DIR/lib $PHP_SABLOT_JS_LIBS -lexpat -liconv
     ])
 
     AC_DEFINE(HAVE_SABLOT_BACKEND, 1, [ ])
