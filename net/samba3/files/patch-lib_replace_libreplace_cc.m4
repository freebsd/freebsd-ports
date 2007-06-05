--- lib/replace/libreplace_cc.m4.orig	Thu Mar  1 05:54:23 2007
+++ lib/replace/libreplace_cc.m4	Mon Jun  4 21:20:13 2007
@@ -131,6 +131,10 @@
 AC_CHECK_TYPE(intptr_t, unsigned long long)
 AC_CHECK_TYPE(ptrdiff_t, unsigned long long)
 
+if test x"$ac_cv_type_intptr_t" = x"yes"; then
+	AC_DEFINE(HAVE_INTPTR_T,1,[Whether the host has intptr_t])
+fi
+
 if test x"$ac_cv_type_long_long" != x"yes";then
 	AC_MSG_ERROR([LIBREPLACE needs type 'long long'])
 fi
