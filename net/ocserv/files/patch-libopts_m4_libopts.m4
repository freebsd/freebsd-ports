--- libopts/m4/libopts.m4.orig	2015-12-01 10:21:06 UTC
+++ libopts/m4/libopts.m4
@@ -55,6 +55,7 @@ AC_DEFUN([INVOKE_LIBOPTS_MACROS_FIRST],[
   AS_HELP_STRING([--disable-nls],[disable nls support in libopts]))
   AS_IF([test "x$enable_nls" != "xno" && \
   test "X${ac_cv_header_libintl_h}" = Xyes], [
+  AC_CHECK_LIB(intl,gettext)
   AC_DEFINE([ENABLE_NLS],[1],[nls support in libopts])])
 
   # --------------------------------------------
@@ -106,7 +107,6 @@ AC_DEFUN([INVOKE_LIBOPTS_MACROS_FIRST],[
   # AC_CHECK_LIB
   # ------------
   AC_CHECK_LIB(gen, pathfind)
-  AC_CHECK_LIB(intl,gettext)
   AC_FUNC_VPRINTF
   AC_FUNC_FORK
   AC_CHECK_FUNCS([mmap canonicalize_file_name snprintf strdup strchr \
