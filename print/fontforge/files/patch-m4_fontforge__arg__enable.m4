--- m4/fontforge_arg_enable.m4.orig	2019-08-01 08:28:36 UTC
+++ m4/fontforge_arg_enable.m4
@@ -232,7 +232,7 @@ AC_DEFUN([FONTFORGE_ARG_ENABLE_WOFF2],
 AC_ARG_ENABLE([woff2],
         [AS_HELP_STRING([--enable-woff2],
                 [Enable WOFF2 support.])],
-        [use_woff2=yes])
+        [use_woff2="${enableval}"])
 if test x$use_woff2 = xyes ; then
     PKG_CHECK_MODULES([WOFF2],[libwoff2enc,libwoff2dec],
     [
