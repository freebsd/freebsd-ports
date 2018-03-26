--- cmake/Version.cmake.orig	2018-03-26 15:12:24 UTC
+++ cmake/Version.cmake
@@ -28,11 +28,11 @@
 
 function (write_static_version_header hash)
   set(VERSIONTAG "${hash}")
-  configure_file("src/version.cpp.in" "version.cpp")
+  configure_file("${CMAKE_BINARY_DIR}/src/version.cpp.in" "${CMAKE_BINARY_DIR}/version.cpp")
 endfunction ()
 
 find_package(Git QUIET)
-if ("$Format:$" STREQUAL "")
+if (TRUE)
   # We're in a tarball; use hard-coded variables.
   write_static_version_header("release")
 elseif (GIT_FOUND OR Git_FOUND)
