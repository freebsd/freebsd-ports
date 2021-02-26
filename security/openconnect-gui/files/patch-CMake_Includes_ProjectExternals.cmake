--- CMake/Includes/ProjectExternals.cmake.orig	2018-03-25 21:49:15 UTC
+++ CMake/Includes/ProjectExternals.cmake
@@ -22,7 +22,6 @@ include(ExternalProject)
 
 file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/external/include)
 
-include(ProjectExternals_spdlog)
 include(ProjectExternals_qt-solutions)
 if(MINGW)
     include(ProjectExternals_openconnect)
