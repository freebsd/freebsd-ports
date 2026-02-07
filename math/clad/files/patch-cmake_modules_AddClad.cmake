--- cmake/modules/AddClad.cmake.orig	2024-02-29 15:28:44 UTC
+++ cmake/modules/AddClad.cmake
@@ -1,15 +1,15 @@ if (CLAD_ENABLE_BENCHMARKS)
 if (CLAD_ENABLE_BENCHMARKS)
   # Find the current branch.
-  execute_process(WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
-                  COMMAND git rev-parse HEAD
-                  OUTPUT_VARIABLE CURRENT_REPO_COMMIT
-                  OUTPUT_STRIP_TRAILING_WHITESPACE)
-  string(REPLACE "/" "" CURRENT_REPO_COMMIT ${CURRENT_REPO_COMMIT})
+  #execute_process(WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
+  #                COMMAND git rev-parse HEAD
+  #                OUTPUT_VARIABLE CURRENT_REPO_COMMIT
+  #                OUTPUT_STRIP_TRAILING_WHITESPACE)
+  #string(REPLACE "/" "" CURRENT_REPO_COMMIT ${CURRENT_REPO_COMMIT})
 
 # Ask cmake to reconfigure each time we change the branch so that it can change
 # the value of CURRENT_REPO_COMMIT.
-set_property(DIRECTORY APPEND PROPERTY
-             CMAKE_CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/.git/HEAD")
+#set_property(DIRECTORY APPEND PROPERTY
+#             CMAKE_CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/.git/HEAD")
 
 endif(CLAD_ENABLE_BENCHMARKS)
 
