--- cf/check-compile-et.m4.orig	2022-11-17 06:42:48.000000000 -0800
+++ cf/check-compile-et.m4	2022-11-17 15:10:14.877952000 -0800
@@ -7,7 +7,7 @@
 
 krb_cv_compile_et="no"
 krb_cv_com_err_need_r=""
-krb_cv_compile_et_cross=no
+krb_cv_compile_et_cross=yes
 if test "${COMPILE_ET}" != "no"; then
 
 dnl We have compile_et.  Now let's see if it supports `prefix' and `index'.
