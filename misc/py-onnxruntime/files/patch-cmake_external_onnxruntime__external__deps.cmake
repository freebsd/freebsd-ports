-- Force bundled Protobuf and ONNX instead of find_package, because the
-- installed system versions (e.g., protobuf 29.x, ONNX 1.22) drag in
-- targets like absl::if_constexpr and utf8_range::utf8_range that are
-- not provided by the bundled dependencies and break the build.

--- cmake/external/onnxruntime_external_deps.cmake.orig	2026-09-10 06:09:41 UTC
+++ cmake/external/onnxruntime_external_deps.cmake
@@ -186,10 +186,10 @@ if(Patch_FOUND)
 #   for cross-compiling
 #2. if ONNX_CUSTOM_PROTOC_EXECUTABLE is not set, Compile everything(including protoc) from source code.
 if(Patch_FOUND)
-  set(ONNXRUNTIME_PROTOBUF_PATCH_COMMAND ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_android_log.patch &&
-                                         ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_msvc_unreachable_code.patch &&
-                                         ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_msvc_map_unreachable_code.patch &&
-                                         ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_compiler_incomplete_type.patch)
+  set(ONNXRUNTIME_PROTOBUF_PATCH_COMMAND ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_android_log.patch &&
+                                         ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_msvc_unreachable_code.patch &&
+                                         ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_msvc_map_unreachable_code.patch &&
+                                         ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/protobuf/protobuf_compiler_incomplete_type.patch)
 else()
  set(ONNXRUNTIME_PROTOBUF_PATCH_COMMAND "")
 endif()
@@ -201,7 +201,6 @@ onnxruntime_fetchcontent_declare(
   URL_HASH SHA1=${DEP_SHA1_protobuf}
   PATCH_COMMAND ${ONNXRUNTIME_PROTOBUF_PATCH_COMMAND}
   EXCLUDE_FROM_ALL
-  FIND_PACKAGE_ARGS NAMES Protobuf protobuf
 )
 
 set(protobuf_BUILD_TESTS OFF CACHE BOOL "Build protobuf tests" FORCE)
@@ -277,7 +276,7 @@ onnxruntime_fetchcontent_declare(
   URL_HASH SHA1=${DEP_SHA1_date}
   EXCLUDE_FROM_ALL
   PATCH_COMMAND
-    ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/date/date.patch
+    ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/date/date.patch
   FIND_PACKAGE_ARGS 3...<4 NAMES date
 )
 onnxruntime_fetchcontent_makeavailable(date)
@@ -378,7 +377,7 @@ if (CPUINFO_SUPPORTED)
           # https://github.com/pytorch/cpuinfo/pull/324
           ${Patch_EXECUTABLE} -p1 < ${PROJECT_SOURCE_DIR}/patches/cpuinfo/patch_vcpkg_arm64ec_support.patch &&
           # https://github.com/pytorch/cpuinfo/pull/400
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 <
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 <
           ${PROJECT_SOURCE_DIR}/patches/cpuinfo/enable_deinit_refcounting.patch
       )
     elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
@@ -392,7 +391,7 @@ if (CPUINFO_SUPPORTED)
           # https://github.com/microsoft/onnxruntime/issues/10038
           ${Patch_EXECUTABLE} -p1 < ${PROJECT_SOURCE_DIR}/patches/cpuinfo/fix_missing_sysfs_fallback.patch &&
           # https://github.com/pytorch/cpuinfo/pull/400
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 <
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 <
           ${PROJECT_SOURCE_DIR}/patches/cpuinfo/enable_deinit_refcounting.patch
       )
     else()
@@ -403,7 +402,7 @@ if (CPUINFO_SUPPORTED)
         EXCLUDE_FROM_ALL
         PATCH_COMMAND
           # https://github.com/pytorch/cpuinfo/pull/400
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 <
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 <
           ${PROJECT_SOURCE_DIR}/patches/cpuinfo/enable_deinit_refcounting.patch
       )
     endif()
@@ -421,7 +420,7 @@ onnxruntime_fetchcontent_declare(
   URL_HASH SHA1=${DEP_SHA1_microsoft_gsl}
   # Stringify fix for GSL_SUPPRESS on MSVC (C4875). Remove when GSL ships a release
   # containing microsoft/GSL#1213 (commit 543d0dd).
-  PATCH_COMMAND ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/gsl/1213.patch
+  PATCH_COMMAND ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/gsl/1213.patch
   EXCLUDE_FROM_ALL
   FIND_PACKAGE_ARGS 4.0 NAMES Microsoft.GSL
 )
@@ -466,7 +465,7 @@ if(Patch_FOUND)
 set(FLATBUFFERS_BUILD_FLATHASH OFF CACHE BOOL "FLATBUFFERS_BUILD_FLATHASH" FORCE)
 set(FLATBUFFERS_BUILD_FLATLIB ON CACHE BOOL "FLATBUFFERS_BUILD_FLATLIB" FORCE)
 if(Patch_FOUND)
-  set(ONNXRUNTIME_FLATBUFFERS_PATCH_COMMAND ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/flatbuffers/flatbuffers.patch)
+  set(ONNXRUNTIME_FLATBUFFERS_PATCH_COMMAND ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/flatbuffers/flatbuffers.patch)
 else()
  set(ONNXRUNTIME_FLATBUFFERS_PATCH_COMMAND "")
 endif()
@@ -517,7 +516,7 @@ if(Patch_FOUND)
 endif()
 
 if(Patch_FOUND)
-  set(ONNXRUNTIME_ONNX_PATCH_COMMAND ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/onnx/onnx.patch)
+  set(ONNXRUNTIME_ONNX_PATCH_COMMAND ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/onnx/onnx.patch)
 else()
   set(ONNXRUNTIME_ONNX_PATCH_COMMAND "")
 endif()
@@ -543,7 +542,6 @@ onnxruntime_fetchcontent_declare(
   URL_HASH SHA1=${DEP_SHA1_onnx}
   PATCH_COMMAND ${ONNXRUNTIME_ONNX_PATCH_COMMAND}
   EXCLUDE_FROM_ALL
-  FIND_PACKAGE_ARGS NAMES ONNX onnx
 )
 
 onnxruntime_fetchcontent_makeavailable(onnx)
@@ -627,7 +625,7 @@ if(onnxruntime_ENABLE_TRAINING OR (onnxruntime_ENABLE_
   # Once code under orttraining/orttraining/models dir is removed "onnxruntime_ENABLE_TRAINING" should be removed from
   # this conditional
   if(Patch_FOUND)
-    set(ONNXRUNTIME_CXXOPTS_PATCH_COMMAND ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/cxxopts/gcc-15-compat.patch)
+    set(ONNXRUNTIME_CXXOPTS_PATCH_COMMAND ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/cxxopts/gcc-15-compat.patch)
   else()
     set(ONNXRUNTIME_CXXOPTS_PATCH_COMMAND "")
   endif()
@@ -795,20 +793,20 @@ if (onnxruntime_USE_WEBGPU)
           #   in emwgpu implementation, the buffer destroy won't happen. This change adds a destructor to the buffer class
           #   to destroy the buffer when the refcount is 0 for non-external buffers.
           #
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_destroy_buffer_on_destructor.patch &&
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_destroy_buffer_on_destructor.patch &&
 
           # The dawn_binskim.patch contains the following changes:
           #
           # - (private) Fulfill the BinSkim requirements
           #   Some build warnings are not allowed to be disabled in project level.
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_binskim.patch &&
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_binskim.patch &&
 
           # The safari_polyfill.patch contains the following changes:
           #
           # - (private) Fix compatibility issues with Safari. Contains the following changes:
           #   - Polyfill for `device.AdapterInfo` (returns `undefined` in Safari v26.0)
           #
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/safari_polyfill.patch &&
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/safari_polyfill.patch &&
 
           # The dawn_device_lost_keepalive.patch contains the following changes:
           #
@@ -818,7 +816,7 @@ if (onnxruntime_USE_WEBGPU)
           #   was 0. This silently dropped all subsequent WebGPU callbacks (e.g. requestAdapter),
           #   breaking session re-creation after device destruction.
           #
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_device_lost_keepalive.patch &&
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_device_lost_keepalive.patch &&
 
           # The dawn_dxc_output_dir.patch contains the following changes:
           #
@@ -828,7 +826,7 @@ if (onnxruntime_USE_WEBGPU)
           #   because dxcompiler.dll ends up in the default output path instead of CMAKE_BINARY_DIR/$<CONFIG>,
           #   and the copy_dxil_dll target copies dxil.dll to a different location.
           #
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_dxc_output_dir.patch &&
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_dxc_output_dir.patch &&
 
           # The dawn_parallel_build_fix.patch contains the following changes:
           #
@@ -855,7 +853,7 @@ if (onnxruntime_USE_WEBGPU)
           #      build ordering is preserved through the emdawnwebgpu_c -> emdawnwebgpu_c_include
           #      -> emdawnwebgpu_headers_gen dependency chain.
           #
-          ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_parallel_build_fix.patch &&
+          ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/dawn/dawn_parallel_build_fix.patch &&
 
           # Remove the test folder to speed up potential file scan operations (70k+ files not needed for build).
           # Using <SOURCE_DIR> token ensures the correct absolute path regardless of working directory.
@@ -934,7 +932,7 @@ if(onnxruntime_USE_COREML)
     coremltools
     URL ${DEP_URL_coremltools}
     URL_HASH SHA1=${DEP_SHA1_coremltools}
-    PATCH_COMMAND ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/coremltools/crossplatformbuild.patch
+    PATCH_COMMAND ${Patch_EXECUTABLE} --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/coremltools/crossplatformbuild.patch
     EXCLUDE_FROM_ALL
   )
   # we don't build directly so use Populate. selected files are built from onnxruntime_providers_coreml.cmake
@@ -1074,7 +1072,7 @@ if(onnxruntime_USE_TELEMETRY AND NOT WIN32)
               "onnxruntime_USE_TELEMETRY with the FetchContent cpp_client_telemetry fallback requires the patch tool.")
     endif()
     set(ONNXRUNTIME_CPP_CLIENT_TELEMETRY_PATCH_COMMAND
-        ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 <
+        ${Patch_EXECUTABLE} --ignore-whitespace -p1 <
         ${PROJECT_SOURCE_DIR}/patches/cpp_client_telemetry/cpp_client_telemetry.patch)
     onnxruntime_fetchcontent_declare(
       cpp_client_telemetry
