-- disable git invocation because we don't have a git repo here

--- cmake/Provenance.cmake.orig	2025-12-17 19:20:45 UTC
+++ cmake/Provenance.cmake
@@ -28,38 +28,14 @@ set(post_configure_file ${post_configure_dir}/provenan
 set(pre_configure_file ${pre_configure_dir}/provenance.cpp.in)
 set(post_configure_file ${post_configure_dir}/provenance.cpp)
 
-function(CheckGitWrite git_hash)
-    file(WRITE ${CMAKE_BINARY_DIR}/git-state-parthenon.txt ${git_hash})
-endfunction()
-
-function(CheckGitRead git_hash)
-    if (EXISTS ${CMAKE_BINARY_DIR}/git-state-parthenon.txt)
-        file(STRINGS ${CMAKE_BINARY_DIR}/git-state-parthenon.txt CONTENT)
-        LIST(GET CONTENT 0 var)
-
-        set(${git_hash} ${var} PARENT_SCOPE)
-    endif ()
-endfunction()
-
 function(CheckGitVersion)
     # Get the latest abbreviated commit hash of the working branch
-    execute_process(
-        COMMAND git log -1 --format=%h
-        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
-        OUTPUT_VARIABLE PARTH_GIT_HASH
-        OUTPUT_STRIP_TRAILING_WHITESPACE
-        )
+    set(PARTH_GIT_HASH "01234567890123456789012345678901234567890123456789")
 
     # Get the git branch
-    execute_process(
-        COMMAND git rev-parse --abbrev-ref HEAD
-        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
-        OUTPUT_VARIABLE PARTH_GIT_BRANCH
-        OUTPUT_STRIP_TRAILING_WHITESPACE
-    )
+    set(PARTH_GIT_BRANCH "master")
     
     set(PARTH_GIT_HASH_CACHE "INVALID")
-    CheckGitRead(PARTH_GIT_HASH_CACHE)
     if (NOT EXISTS ${post_configure_dir})
         file(MAKE_DIRECTORY ${post_configure_dir})
     endif ()
@@ -73,7 +49,6 @@ function(CheckGitVersion)
     if (NOT ${PARTH_GIT_HASH} STREQUAL ${PARTH_GIT_HASH_CACHE} OR NOT EXISTS ${post_configure_file})
         # Set the PARTH_GIT_HASH_CACHE variable the next build won't have
         # to regenerate the source file.
-        CheckGitWrite(${PARTH_GIT_HASH})
 
         configure_file(${pre_configure_file} ${post_configure_file} @ONLY)
     endif ()
@@ -97,11 +72,6 @@ endfunction()
 
     CheckGitVersion()
 endfunction()
-
-# This is used to run this function from an external cmake process.
-if (RUN_CHECK_GIT_VERSION)
-    CheckGitVersion()
-endif ()
 
 # Other information:
 # Compiler
