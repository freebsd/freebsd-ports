--- ./lib/replace/libreplace_cc.m4.orig	2008-09-18 06:49:02.000000000 +0000
+++ ./lib/replace/libreplace_cc.m4	2008-10-10 00:42:10.000000000 +0000
@@ -145,6 +145,10 @@
 AC_CHECK_TYPE(uintptr_t, unsigned long long)
 AC_CHECK_TYPE(ptrdiff_t, unsigned long long)
 
+if test x"$ac_cv_type_intptr_t" = x"yes"; then
+	AC_DEFINE(HAVE_INTPTR_T,1,[Whether the host has intptr_t])
+fi
+
 if test x"$ac_cv_type_long_long" != x"yes";then
 	AC_MSG_ERROR([LIBREPLACE needs type 'long long'])
 fi
