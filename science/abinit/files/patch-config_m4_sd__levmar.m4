--- config/m4/sd_levmar.m4.orig	2020-11-10 12:21:53 UTC
+++ config/m4/sd_levmar.m4
@@ -239,6 +239,7 @@ AC_DEFUN([_SD_LEVMAR_CHECK_USE], [
   AC_LANG_PUSH([C])
   AC_LINK_IFELSE([AC_LANG_PROGRAM(
     [[
+#     include <stddef.h>
 #     include <levmar.h>
 
       void dfit_function(double *p, double *y, int m, int n, void *adata)
