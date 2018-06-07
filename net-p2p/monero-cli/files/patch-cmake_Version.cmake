--- cmake/Version.cmake.orig	2018-06-01 14:10:23.694883000 UTC
+++ cmake/Version.cmake	2018-06-01 14:10:35.450366000 UTC
@@ -32,7 +32,7 @@
 endfunction ()
 
 find_package(Git QUIET)
-if ("$Format:$" STREQUAL "")
+if (TRUE)
   # We're in a tarball; use hard-coded variables.
   write_static_version_header("release")
 elseif (GIT_FOUND OR Git_FOUND)
