--- src/addons/score-addon-onnx/3rdparty/onnxruntime-extensions/cmake/externals/json.cmake.orig	2025-11-13 15:39:52 UTC
+++ src/addons/score-addon-onnx/3rdparty/onnxruntime-extensions/cmake/externals/json.cmake
@@ -1,8 +1 @@
-FetchContent_Declare(nlohmann_json
-  URL       https://codeload.github.com/nlohmann/json/zip/refs/tags/v3.11.3
-  URL_HASH  SHA1=5e88795165cc8590138d1f47ce94ee567b85b4d6
-  SOURCE_SUBDIR not_set
-  )
-
-add_compile_definitions(JSON_HAS_CPP_17=1)
-FetchContent_MakeAvailable(nlohmann_json)
+find_package(nlohmann_json CONFIG REQUIRED)
