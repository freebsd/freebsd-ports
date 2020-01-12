--- m4/cs_blas.m4.orig	2019-12-23 11:17:00 UTC
+++ m4/cs_blas.m4
@@ -346,7 +346,7 @@ if test "x$with_blas" != "xno" ; then
     if test "x$with_blas_libs" != "x" ; then
       BLAS_LIBS="$with_blas_libs"
     else
-      BLAS_LIBS="-lblas"
+      BLAS_LIBS="-lcblas -lblas"
     fi
 
     CPPFLAGS="${saved_CPPFLAGS} ${BLAS_CPPFLAGS}"
