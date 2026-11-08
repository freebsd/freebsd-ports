-- Force bundled Protobuf and ONNX instead of find_package, because the
-- installed system versions (e.g., protobuf 29.x, ONNX 1.22) drag in
-- targets like absl::if_constexpr and utf8_range::utf8_range that are
-- not provided by the bundled dependencies and break the build.

--- cmake/external/onnxruntime_external_deps.cmake.orig	2026-09-10 06:09:41 UTC
+++ cmake/external/onnxruntime_external_deps.cmake
@@ -201,7 +201,6 @@ onnxruntime_fetchcontent_declare(
   URL_HASH SHA1=${DEP_SHA1_protobuf}
   PATCH_COMMAND ${ONNXRUNTIME_PROTOBUF_PATCH_COMMAND}
   EXCLUDE_FROM_ALL
-  FIND_PACKAGE_ARGS NAMES Protobuf protobuf
 )
 
 set(protobuf_BUILD_TESTS OFF CACHE BOOL "Build protobuf tests" FORCE)
@@ -543,7 +542,6 @@ onnxruntime_fetchcontent_declare(
   URL_HASH SHA1=${DEP_SHA1_onnx}
   PATCH_COMMAND ${ONNXRUNTIME_ONNX_PATCH_COMMAND}
   EXCLUDE_FROM_ALL
-  FIND_PACKAGE_ARGS NAMES ONNX onnx
 )
 
 onnxruntime_fetchcontent_makeavailable(onnx)
