-- Make the glog ExternalProject PATCH_COMMAND a no-op because glog source files
-- are already patched by the FreeBSD port patch mechanism. Using git commands
-- or patch in ExternalProject would fail (source is a tarball, not a git repo)
-- or double-apply patches, causing the build to hang or fail.
--- cmake/external/glog.cmake.orig	2026-06-19 17:23:24 UTC
+++ cmake/external/glog.cmake
@@ -49,8 +49,8 @@ file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/glog/
 endif()
 # patch
 file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/glog/indent.patch log_indent)
-set(GLOG_PATCH_COMMAND git checkout -- . && git apply --check ${log_indent} &&
-                       git apply ${log_indent})
+# NOTE: Glog source files are patched by FreeBSD port patch mechanism.
+set(GLOG_PATCH_COMMAND ${CMAKE_COMMAND} -E true)
 ExternalProject_Add(
   extern_glog
   ${EXTERNAL_PROJECT_LOG_ARGS} ${SHALLOW_CLONE}
