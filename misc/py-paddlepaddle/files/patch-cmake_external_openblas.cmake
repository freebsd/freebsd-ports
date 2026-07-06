-- Fix build on FreeBSD: OpenBLAS Makefile uses GNU make syntax (ifndef, ifeq,
-- else ifeq, endif conditionals). The system make on FreeBSD is BSD make which
-- does not support this syntax. Use gmake (GNU make) instead.
--- cmake/external/openblas.cmake.orig	2026-06-19 21:37:29 UTC
+++ cmake/external/openblas.cmake
@@ -90,6 +90,11 @@ if(NOT WIN32)
     set(ARM_ARGS TARGET=ARMV8)
   endif()
   set(COMMON_ARGS CC=${OPENBLAS_CC} NO_SHARED=1 NO_LAPACK=1 libs)
+  if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    set(OPENBLAS_MAKE_CMD gmake)
+  else()
+    set(OPENBLAS_MAKE_CMD make)
+  endif()
   ExternalProject_Add(
     extern_openblas
     ${EXTERNAL_PROJECT_LOG_ARGS}
@@ -97,8 +102,8 @@ if(NOT WIN32)
     PREFIX ${CBLAS_PREFIX_DIR}
     INSTALL_DIR ${CBLAS_INSTALL_DIR}
     BUILD_IN_SOURCE 1
-    BUILD_COMMAND make ${ARM_ARGS} -s -j${NPROC} ${COMMON_ARGS} ${OPTIONAL_ARGS}
-    INSTALL_COMMAND make install NO_SHARED=1 NO_LAPACK=1 PREFIX=<INSTALL_DIR>
+    BUILD_COMMAND ${OPENBLAS_MAKE_CMD} ${ARM_ARGS} -s -j${NPROC} ${COMMON_ARGS} ${OPTIONAL_ARGS}
+    INSTALL_COMMAND ${OPENBLAS_MAKE_CMD} install NO_SHARED=1 NO_LAPACK=1 PREFIX=<INSTALL_DIR>
     UPDATE_COMMAND ""
     CONFIGURE_COMMAND ""
     BUILD_BYPRODUCTS ${CBLAS_LIBRARIES})
