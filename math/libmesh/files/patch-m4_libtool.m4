--- m4/libtool.m4.orig	2017-07-25 16:33:31 UTC
+++ m4/libtool.m4
@@ -1948,7 +1948,7 @@ else
   darwin*)
     # if libdl is installed we need to link against it
     AC_CHECK_LIB([dl], [dlopen],
-		[lt_cv_dlopen=dlopen lt_cv_dlopen_libs=-ldl],[
+		[lt_cv_dlopen=dlopen lt_cv_dlopen_libs=],[
     lt_cv_dlopen=dyld
     lt_cv_dlopen_libs=
     lt_cv_dlopen_self=yes
@@ -1971,7 +1971,7 @@ else
 	[AC_CHECK_FUNC([dlopen],
 	      [lt_cv_dlopen=dlopen],
 	  [AC_CHECK_LIB([dl], [dlopen],
-		[lt_cv_dlopen=dlopen lt_cv_dlopen_libs=-ldl],
+		[lt_cv_dlopen=dlopen lt_cv_dlopen_libs=],
 	    [AC_CHECK_LIB([svld], [dlopen],
 		  [lt_cv_dlopen=dlopen lt_cv_dlopen_libs=-lsvld],
 	      [AC_CHECK_LIB([dld], [dld_link],
