-- On FreeBSD, cmake falls into the macOS else() branch and attempts to
-- download precompiled macOS dylibs from paddlepaddledeps.bj.bcebos.com,
-- which fails in a clean build environment with no network access.
-- Add a FreeBSD branch that uses the system OpenBLAS (which includes LAPACK)
-- and replaces the ExternalProject download with a no-op custom target.
--- cmake/external/lapack.cmake.orig	2026-06-20 04:47:39 UTC
+++ cmake/external/lapack.cmake
@@ -48,6 +48,11 @@ elseif(WIN32)
   set(GFORTRAN_LIB "${LAPACK_LIB_DIR}/libgfortran-3.dll")
   set(BLAS_LIB "${LAPACK_LIB_DIR}/libblas.dll")
   set(LAPACK_LIB "${LAPACK_LIB_DIR}/liblapack.dll")
+elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+  # FreeBSD: OpenBLAS provides both BLAS and LAPACK; no download needed.
+  find_library(OPENBLAS_LIB openblas HINTS ${OPENBLAS_ROOT}/lib)
+  set(BLAS_LIB "${OPENBLAS_LIB}" CACHE STRING "" FORCE)
+  set(LAPACK_LIB "${OPENBLAS_LIB}" CACHE STRING "" FORCE)
 else() # MacOS
   if(APPLE AND WITH_ARM)
     set(LAPACK_FILE
@@ -97,31 +102,36 @@ endfunction()
 endfunction()
 
 # Download and check lapack.
-if(EXISTS ${LAPACK_DOWNLOAD_DIR}/${LAPACK_FILE})
-  file(MD5 ${LAPACK_DOWNLOAD_DIR}/${LAPACK_FILE} LAPACK_MD5)
-  if(NOT LAPACK_MD5 STREQUAL LAPACK_URL_MD5)
-    # clean build file
-    file(REMOVE_RECURSE ${LAPACK_PREFIX_DIR})
-    file(REMOVE_RECURSE ${LAPACK_INSTALL_DIR})
+if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+  # On FreeBSD, use system OpenBLAS; no download or ExternalProject needed.
+  add_custom_target(extern_lapack)
+else()
+  if(EXISTS ${LAPACK_DOWNLOAD_DIR}/${LAPACK_FILE})
+    file(MD5 ${LAPACK_DOWNLOAD_DIR}/${LAPACK_FILE} LAPACK_MD5)
+    if(NOT LAPACK_MD5 STREQUAL LAPACK_URL_MD5)
+      # clean build file
+      file(REMOVE_RECURSE ${LAPACK_PREFIX_DIR})
+      file(REMOVE_RECURSE ${LAPACK_INSTALL_DIR})
+      download_lapack()
+    endif()
+  else()
     download_lapack()
   endif()
-else()
-  download_lapack()
-endif()
 
-ExternalProject_Add(
-  extern_lapack
-  ${EXTERNAL_PROJECT_LOG_ARGS}
-  URL ${LAPACK_DOWNLOAD_DIR}/${LAPACK_FILE}
-  URL_MD5 ${LAPACK_URL_MD5}
-  DOWNLOAD_DIR ${LAPACK_DOWNLOAD_DIR}
-  SOURCE_DIR ${LAPACK_LIB_DIR}
-  PREFIX ${LAPACK_PREFIX_DIR}
-  DOWNLOAD_NO_PROGRESS 1
-  PATCH_COMMAND ""
-  UPDATE_COMMAND ""
-  CONFIGURE_COMMAND ""
-  BUILD_COMMAND ""
-  INSTALL_COMMAND ""
-  BUILD_BYPRODUCTS ${BLAS_LIB}
-  BUILD_BYPRODUCTS ${LAPACK_LIB})
+  ExternalProject_Add(
+    extern_lapack
+    ${EXTERNAL_PROJECT_LOG_ARGS}
+    URL ${LAPACK_DOWNLOAD_DIR}/${LAPACK_FILE}
+    URL_MD5 ${LAPACK_URL_MD5}
+    DOWNLOAD_DIR ${LAPACK_DOWNLOAD_DIR}
+    SOURCE_DIR ${LAPACK_LIB_DIR}
+    PREFIX ${LAPACK_PREFIX_DIR}
+    DOWNLOAD_NO_PROGRESS 1
+    PATCH_COMMAND ""
+    UPDATE_COMMAND ""
+    CONFIGURE_COMMAND ""
+    BUILD_COMMAND ""
+    INSTALL_COMMAND ""
+    BUILD_BYPRODUCTS ${BLAS_LIB}
+    BUILD_BYPRODUCTS ${LAPACK_LIB})
+endif()
