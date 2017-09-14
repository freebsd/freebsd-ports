Has been submitted upstream. With ninja, the generated file
is not recognized as a dependency and not generated before it is
#included from other code.

--- CMake/Includes/git_revision_main.cmake.orig	2016-08-28 20:11:26 UTC
+++ CMake/Includes/git_revision_main.cmake
@@ -4,9 +4,9 @@ if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/.git)
     find_package(Git 2.7 REQUIRED)
 endif()
 
-add_custom_target(git_revision ALL)
 add_custom_command(
-    TARGET git_revision
+#    TARGET git_revision
+    OUTPUT ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src
 
     COMMAND ${CMAKE_COMMAND}
@@ -35,5 +35,8 @@ add_custom_command(
         -P ${CMAKE_SOURCE_DIR}/CMake/Includes/git_revision_generate.cmake
         COMMENT "Analyzing Git revision/tag changes..." VERBATIM
 )
-
+add_custom_target(
+        git_revision
+        DEPENDS ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
+)
 add_dependencies(${PROJECT_NAME} git_revision)
