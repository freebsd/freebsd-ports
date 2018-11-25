--- aclocal.m4.orig	2018-10-29 00:47:18 UTC
+++ aclocal.m4
@@ -8619,10 +8619,10 @@ m4_ifndef([_LT_PROG_CXX],		[AC_DEFUN([_L
 # generated from the m4 files accompanying Automake X.Y.
 # (This private macro should not be called outside this file.)
 AC_DEFUN([AM_AUTOMAKE_VERSION],
-[am__api_version='1.14'
+[am__api_version='1.16'
 dnl Some users find AM_AUTOMAKE_VERSION and mistake it for a way to
 dnl require some minimum version.  Point them to the right macro.
-m4_if([$1], [1.14.1], [],
+m4_if([$1], [1.16.1], [],
       [AC_FATAL([Do not call $0, use AM_INIT_AUTOMAKE([$1]).])])dnl
 ])
 
@@ -8638,7 +8638,7 @@ m4_define([_AM_AUTOCONF_VERSION], [])
 # Call AM_AUTOMAKE_VERSION and AM_AUTOMAKE_VERSION so they can be traced.
 # This function is AC_REQUIREd by AM_INIT_AUTOMAKE.
 AC_DEFUN([AM_SET_CURRENT_AUTOMAKE_VERSION],
-[AM_AUTOMAKE_VERSION([1.14.1])dnl
+[AM_AUTOMAKE_VERSION([1.16.1])dnl
 m4_ifndef([AC_AUTOCONF_VERSION],
   [m4_copy([m4_PACKAGE_VERSION], [AC_AUTOCONF_VERSION])])dnl
 _AM_AUTOCONF_VERSION(m4_defn([AC_AUTOCONF_VERSION]))])
