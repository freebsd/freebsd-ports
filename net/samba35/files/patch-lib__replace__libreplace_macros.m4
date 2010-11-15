--- ./lib/replace/libreplace_macros.m4.orig	2010-10-07 18:41:16.000000000 +0200
+++ ./lib/replace/libreplace_macros.m4	2010-11-15 03:29:16.000000000 +0100
@@ -293,12 +293,12 @@
 			$2
 		}
 	])],[
-		AS_TR_SH([ac_cv_c_prototype_$1])=yes
+		eval AS_TR_SH([ac_cv_c_prototype_$1])=yes
 	],[
-		AS_TR_SH([ac_cv_c_prototype_$1])=no
+		eval AS_TR_SH([ac_cv_c_prototype_$1])=no
 	])
 )
-AS_IF([test $AS_TR_SH([ac_cv_c_prototype_$1]) = yes],[$3],[$4])
+AS_IF([eval test \$AS_TR_SH([ac_cv_c_prototype_$1]) = yes],[$3],[$4])
 ])
 
 AC_DEFUN(LIBREPLACE_PROVIDE_HEADER, 
