--- CMake/ParaViewClient.cmake.orig	2024-12-29 23:38:49 UTC
+++ CMake/ParaViewClient.cmake
@@ -569,6 +569,7 @@ function (paraview_client_documentation)
   find_program(qt_xmlpatterns_executable
     NAMES xmlpatterns-qt5 xmlpatterns
     HINTS "${Qt5_DIR}/../../../bin"
+          "${Qt5_DIR}/../../qt5/bin"
           "${Qt5_DIR}/../../../libexec/qt5/bin"
     DOC   "Path to xmlpatterns")
   mark_as_advanced(qt_xmlpatterns_executable)
