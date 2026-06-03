--- CMake/ParaViewClient.cmake.orig	2025-09-25 09:24:50 UTC
+++ CMake/ParaViewClient.cmake
@@ -593,7 +593,7 @@ function (paraview_client_documentation)
     include("${_ParaViewClient_cmake_dir}/paraview-find-package-helpers.cmake" OPTIONAL)
     find_program(qt_xmlpatterns_executable
       NAMES xmlpatterns-qt5 xmlpatterns
-      HINTS "${Qt5_DIR}/../../../bin"
+      HINTS "${Qt5_DIR}/../../qt5/bin"
             "${Qt5_DIR}/../../../libexec/qt5/bin"
       DOC   "Path to xmlpatterns")
     mark_as_advanced(qt_xmlpatterns_executable)
