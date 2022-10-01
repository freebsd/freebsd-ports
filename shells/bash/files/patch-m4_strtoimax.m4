--- m4/strtoimax.m4.orig	2022-04-11 20:31:52 UTC
+++ m4/strtoimax.m4
@@ -29,7 +29,7 @@ AC_CACHE_VAL(bash_cv_func_strtoimax,
   fi
 ])
 AC_MSG_RESULT($bash_cv_func_strtoimax)
-if test $bash_cv_func_strtoimax = yes; then
+if test $bash_cv_func_strtoimax = no; then
 AC_LIBOBJ(strtoimax)
 fi
 ])
