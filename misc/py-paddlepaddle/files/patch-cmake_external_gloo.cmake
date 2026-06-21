-- Make the gloo ExternalProject PATCH_COMMAND a no-op because gloo source
-- files are already patched by the FreeBSD port patch mechanism. Using git or
-- patch commands in ExternalProject would double-apply patches, causing the
-- build to hang (FreeBSD patch prompts interactively on hunk failure) or fail.
--- cmake/external/gloo.cmake.orig	2026-06-19 17:23:24 UTC
+++ cmake/external/gloo.cmake
@@ -32,21 +32,8 @@ set(GLOO_LIBRARIES
     CACHE FILEPATH "gloo library." FORCE)
 
 # Setup gloo patch command
-set(GLOO_PATCH_COMMAND git checkout -- . && git checkout ${GLOO_TAG})
-
-file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/gloo/device.cc.patch
-     native_dst)
-file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/gloo/types.h.patch
-     types_header)
-file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/gloo/linux.cc.patch
-     linux_cc_ethtool)
-
-# cmake-format: off
-list(APPEND GLOO_PATCH_COMMAND
-    && patch -Nd ${GLOO_SOURCE_DIR}/gloo/transport/tcp < ${native_dst}
-    && patch -Nd ${GLOO_SOURCE_DIR}/gloo/ < ${types_header}
-    && patch -Nd ${GLOO_SOURCE_DIR}/gloo/common/ < ${linux_cc_ethtool})
-# cmake-format: on
+# NOTE: Gloo source files are patched by FreeBSD port patch mechanism.
+set(GLOO_PATCH_COMMAND ${CMAKE_COMMAND} -E true)
 
 set(GLOO_CMAKE_C_FLAGS "-O3 -fPIC")
 set(GLOO_CMAKE_CXX_FLAGS "-O3 -fPIC")
