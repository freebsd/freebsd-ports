--- cmake/external/protobuf.cmake.orig	2026-06-19 08:48:02 UTC
+++ cmake/external/protobuf.cmake
@@ -254,8 +254,8 @@ function(build_protobuf TARGET_NAME)
     PREFIX ${PROTOBUF_PREFIX_DIR}
     SOURCE_DIR ${SOURCE_DIR}
     UPDATE_COMMAND ""
-    PATCH_COMMAND
-    COMMAND cd ${SOURCE_DIR} && git checkout ${PROTOBUF_TAG}
+    # NOTE: git checkout removed for FreeBSD ports (source is tarball, not git repo)
+    PATCH_COMMAND ""
     DEPENDS zlib
     CONFIGURE_COMMAND
       ${CMAKE_COMMAND} ${SOURCE_DIR}/cmake ${OPTIONAL_ARGS} -G${CMAKE_GENERATOR}
