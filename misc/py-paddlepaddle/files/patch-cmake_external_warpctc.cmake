-- Make the warpctc ExternalProject PATCH_COMMAND a no-op because warpctc source
-- files are already patched by the FreeBSD port patch mechanism. Using git or
-- patch commands in ExternalProject would double-apply patches, causing the
-- build to fail with "already applied" errors.
--- cmake/external/warpctc.cmake.orig	2026-06-19 17:23:24 UTC
+++ cmake/external/warpctc.cmake
@@ -31,10 +31,8 @@ else()
       git checkout -- . && git checkout ${WARPCTC_TAG} && git apply
       ${PADDLE_SOURCE_DIR}/patches/warpctc/CMakeLists.txt.cuda.patch)
 else()
-  set(WARPCTC_PATCH_CUDA_COMMAND
-      git checkout -- . && git checkout ${WARPCTC_TAG} && patch -Nd
-      ${SOURCE_DIR} <
-      ${PADDLE_SOURCE_DIR}/patches/warpctc/CMakeLists.txt.cuda.patch)
+  # NOTE: Warpctc CMakeLists.txt is patched by FreeBSD port patch mechanism.
+  set(WARPCTC_PATCH_CUDA_COMMAND ${CMAKE_COMMAND} -E true)
 endif()
 
 if(NOT WIN32 AND WITH_GPU)
