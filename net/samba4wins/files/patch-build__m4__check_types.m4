--- ./build/m4/check_types.m4.orig	2009-01-19 04:57:18.000000000 +0000
+++ ./build/m4/check_types.m4	2009-01-19 04:57:30.000000000 +0000
@@ -21,7 +21,7 @@
 AC_CHECK_SIZEOF(int,cross)
 AC_CHECK_SIZEOF(long,cross)
 AC_CHECK_SIZEOF(long long,cross)
-if test x"$ac_cv_type_long_long" != x"yes";then
+if test x"$ac_cv_type_long_long" = x"yes";then
 	AC_MSG_ERROR([Sorry we need type 'long long'])
 fi
 if test $ac_cv_sizeof_long_long -lt 8;then
