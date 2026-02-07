--- CMake/GetGitRevisionDescription.cmake.orig	2025-04-30 22:25:21 UTC
+++ CMake/GetGitRevisionDescription.cmake
@@ -67,7 +67,7 @@ function(get_git_head_revision _refspecvar _hashvar)
   endif()
   if (GIT_DIR STREQUAL "")
     set(${_refspecvar} "GITDIR-NOTFOUND" PARENT_SCOPE)
-    set(${_hashvar} "GITDIR-NOTFOUND" PARENT_SCOPE)
+    set(${_hashvar} "b8b08b0" PARENT_SCOPE)
     return()
   endif()
 
