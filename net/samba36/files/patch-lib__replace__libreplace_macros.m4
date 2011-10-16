--- ./lib/replace/libreplace_macros.m4.orig	2011-10-12 01:38:14.000000000 +0200
+++ ./lib/replace/libreplace_macros.m4	2011-10-12 01:39:36.000000000 +0200
@@ -298,7 +298,7 @@
 		eval AS_TR_SH([ac_cv_c_prototype_$1])=no
 	])
 )
-AS_IF([test $AS_TR_SH([ac_cv_c_prototype_$1]) = yes],[$3],[$4])
+AS_IF([eval test \$AS_TR_SH([ac_cv_c_prototype_$1]) = yes],[$3],[$4])
 ])
 
 AC_DEFUN(LIBREPLACE_PROVIDE_HEADER, 
