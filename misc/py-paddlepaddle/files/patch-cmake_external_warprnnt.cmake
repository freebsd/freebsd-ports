-- Make the warprnnt ExternalProject PATCH_COMMAND a no-op because warprnnt
-- source files are already patched by the FreeBSD port patch mechanism. Using
-- git or patch commands in ExternalProject would double-apply patches, causing
-- the build to fail with "already applied" errors.
--- cmake/external/warprnnt.cmake.orig	2026-06-19 17:23:24 UTC
+++ cmake/external/warprnnt.cmake
@@ -36,10 +36,8 @@ else()
         "<SOURCE_DIR>/")
   endif()
 else()
-  set(WARPCTC_PATCH_CUDA_COMMAND
-      git checkout -- . && git checkout ${WARPRNNT_TAG} && patch -Nd
-      ${SOURCE_DIR} <
-      ${PADDLE_SOURCE_DIR}/patches/warprnnt/CMakeLists.txt.cuda.patch)
+  # NOTE: Warprnnt CMakeLists.txt is patched by FreeBSD port patch mechanism.
+  set(WARPCTC_PATCH_CUDA_COMMAND ${CMAKE_COMMAND} -E true)
 endif()
 if(WITH_ROCM)
   set(WARPRNNT_PATCH_ROCM_COMMAND
