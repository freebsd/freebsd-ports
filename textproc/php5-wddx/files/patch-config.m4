--- config.m4.orig	Mon Jul 26 09:05:10 2004
+++ config.m4	Mon Jul 26 09:07:46 2004
@@ -5,6 +5,9 @@
 PHP_ARG_ENABLE(wddx,whether to enable WDDX support,
 [  --enable-wddx           Enable WDDX support.])
 
+PHP_ARG_WITH(libxml-dir, libxml2 install dir,
+[  --with-libxml-dir=<DIR>    WDDX: libxml2 install prefix], no, no)
+
 if test "$PHP_WDDX" != "no"; then
   if test "$ext_shared" != "yes" && test "$enable_xml" = "no"; then
     AC_MSG_WARN(Activating XML)
@@ -12,4 +15,9 @@
   fi
   AC_DEFINE(HAVE_WDDX, 1, [ ])
   PHP_NEW_EXTENSION(wddx, wddx.c, $ext_shared)
+
+  PHP_SETUP_LIBXML(WDDX_SHARED_LIBADD, [
+  ], [
+    AC_MSG_ERROR([xml2-config not found. Please check your libxml2 installation.])
+  ])
 fi
