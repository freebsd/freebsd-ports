-- Make the eigen3 ExternalProject PATCH_COMMAND a no-op because eigen source
-- files are already patched by the FreeBSD port patch mechanism. Using git or
-- patch commands in ExternalProject would double-apply patches, causing the
-- build to hang (FreeBSD patch prompts interactively on hunk failure) or fail.
--- cmake/external/eigen.cmake.orig	2026-06-19 17:23:24 UTC
+++ cmake/external/eigen.cmake
@@ -41,13 +41,12 @@ file(TO_NATIVE_PATH "${PADDLE_SOURCE_DIR}/patches/eige
 
 file(TO_NATIVE_PATH "${PADDLE_SOURCE_DIR}/patches/eigen/TensorRandom.h.patch"
      tensor_random_header)
-# See: [Why calling some `git` commands before `patch`?]
-set(EIGEN_PATCH_COMMAND git checkout -- . && git checkout ${EIGEN_TAG} && git
-                        apply ${tensor_random_header})
+# NOTE: Eigen source files are patched by FreeBSD port patch mechanism.
+set(EIGEN_PATCH_COMMAND ${CMAKE_COMMAND} -E true)
 if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
   file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/eigen/Complex.h.patch
        complex_header)
-  set(EIGEN_PATCH_COMMAND ${EIGEN_PATCH_COMMAND} && git apply ${complex_header})
+  # No-op: Complex.h patch already applied by FreeBSD port patch mechanism.
 endif()
 
 set(EIGEN_INCLUDE_DIR ${SOURCE_DIR})
