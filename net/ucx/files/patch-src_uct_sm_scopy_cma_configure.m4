--- src/uct/sm/scopy/cma/configure.m4.orig	2026-09-14 16:35:41 UTC
+++ src/uct/sm/scopy/cma/configure.m4
@@ -21,6 +21,12 @@ AS_IF([test "x$enable_cma" != xno],
       ]
 )
 
+AS_IF([test "x$cma_happy" != xno],
+      [AC_DEFINE([HAVE_CMA], [1],
+                 [Define to 1 if CMA transport is available])],
+      [AC_DEFINE([HAVE_CMA], [0],
+                 [Define to 0 if CMA transport is unavailable])])
+
 AM_CONDITIONAL([HAVE_CMA], [test "x$cma_happy" != xno])
 AC_CONFIG_FILES([src/uct/sm/scopy/cma/Makefile
                  src/uct/sm/scopy/cma/ucx-cma.pc])
