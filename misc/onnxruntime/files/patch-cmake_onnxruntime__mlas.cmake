--- cmake/onnxruntime_mlas.cmake.orig	2026-09-02 19:55:21 UTC
+++ cmake/onnxruntime_mlas.cmake
@@ -617,6 +617,15 @@ else()
         endif()
     endif()
     if(POWER AND MLAS_SOURCE_IS_NOT_SET)
+        check_cxx_source_compiles("
+          #ifndef __VSX__
+          #error VSX is not supported
+          #endif
+          int main() { return 0; }"
+          MLAS_HAS_VSX
+        )
+    endif()
+    if(POWER AND MLAS_HAS_VSX AND MLAS_SOURCE_IS_NOT_SET)
         set(mlas_platform_srcs
           ${MLAS_SRC_DIR}/power/SgemmKernelPower.cpp
           ${MLAS_SRC_DIR}/dgemm.cpp
