- workaround for https://gitlab.kitware.com/paraview/paraview/-/issues/21817

--- VTK/CMake/FindExprTk.cmake.orig	2023-03-11 22:27:31 UTC
+++ VTK/CMake/FindExprTk.cmake
@@ -21,8 +21,8 @@ mark_as_advanced(ExprTk_INCLUDE_DIR)
 
 if (ExprTk_INCLUDE_DIR)
   file(STRINGS "${ExprTk_INCLUDE_DIR}/exprtk.hpp" _exprtk_version_header
-    REGEX "static const char\\* version")
-  string(REGEX MATCH "static const char\\* version = \"([0-9.]+)\"" _exprtk_version_match "${_exprtk_version_header}")
+    REGEX "static char_cptr *version")
+  string(REGEX MATCH "static char_cptr *version = \"([0-9.]+)\"" _exprtk_version_match "${_exprtk_version_header}")
   set(ExprTk_VERSION "${CMAKE_MATCH_1}")
   unset(_exprtk_version_header)
   unset(_exprtk_version_match)
