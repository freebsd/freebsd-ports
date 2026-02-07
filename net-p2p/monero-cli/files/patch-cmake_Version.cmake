--- cmake/Version.cmake.orig	2025-10-07 19:25:41 UTC
+++ cmake/Version.cmake
@@ -32,7 +32,7 @@ find_package(Git QUIET)
 endfunction ()
 
 find_package(Git QUIET)
-if ("$Format:$" STREQUAL "")
+if (TRUE)
   # We're in a tarball; use hard-coded variables.
   set(VERSION_IS_RELEASE "true")
   write_version("release")
