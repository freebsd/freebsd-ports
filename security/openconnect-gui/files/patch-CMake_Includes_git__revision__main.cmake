--- CMake/Includes/git_revision_main.cmake.orig	2021-02-18 00:09:34 UTC
+++ CMake/Includes/git_revision_main.cmake
@@ -4,9 +4,8 @@ if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/.git)
     find_package(Git 2.7 REQUIRED)
 endif()
 
-add_custom_target(git_revision ALL)
 add_custom_command(
-    TARGET git_revision
+    OUTPUT ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src
 
     COMMAND ${CMAKE_COMMAND}
@@ -35,6 +34,11 @@ add_custom_command(
         -DAPPLE=${APPLE}
         -P ${CMAKE_SOURCE_DIR}/CMake/Includes/git_revision_generate.cmake
         COMMENT "Analyzing Git revision/tag changes..." VERBATIM
+)
+
+add_custom_target(
+        git_revision
+        DEPENDS ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
 )
 
 # explicitly say that the executable depends on the git_revision
