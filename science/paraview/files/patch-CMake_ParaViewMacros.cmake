Prior to 3.12 cmake silently created an empty destination directory if the origin of the copy_directory does not exist.

--- CMake/ParaViewMacros.cmake.orig	2018-07-20 20:59:05 UTC
+++ CMake/ParaViewMacros.cmake
@@ -382,6 +382,7 @@ function(build_help_project name)
     set (copy_directory_command
       # copy all htmls from source to destination directory (same location where the
       # qhp file is present.
+      COMMAND ${CMAKE_COMMAND} -E make_directory "${arg_DOCUMENTATION_SOURCE_DIR}"
       COMMAND ${CMAKE_COMMAND} -E copy_directory
               "${arg_DOCUMENTATION_SOURCE_DIR}"
               "${arg_DESTINATION_DIRECTORY}"
