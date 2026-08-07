-- Provide a fallback Python::NumPy imported target for builds where CMake's
-- FindPython does not detect NumPy 2.x headers (e.g. in poudriere). The
-- include directory is passed via ONNXRUNTIME_NUMPY_INCLUDE_DIR in the Makefile.

--- cmake/onnxruntime_python.cmake.orig	2026-08-06 23:27:52 UTC
+++ cmake/onnxruntime_python.cmake
@@ -213,6 +213,14 @@ endif()
   # onnxruntime_pybind11_state is a DLL
   target_sources(onnxruntime_pybind11_state PRIVATE "${ONNXRUNTIME_ROOT}/core/dll/dllmain.cc")
 endif()
+# FreeBSD: CMake's FindPython may not detect NumPy 2.x headers in poudriere,
+# so provide a fallback imported target with the include directory supplied by
+# the port's Makefile via ONNXRUNTIME_NUMPY_INCLUDE_DIR.
+if(NOT TARGET Python::NumPy)
+  add_library(Python::NumPy INTERFACE IMPORTED)
+  set_target_properties(Python::NumPy PROPERTIES
+    INTERFACE_INCLUDE_DIRECTORIES "${ONNXRUNTIME_NUMPY_INCLUDE_DIR}")
+endif()
 target_link_libraries(onnxruntime_pybind11_state PRIVATE
     onnxruntime_session
     ${onnxruntime_libs}
