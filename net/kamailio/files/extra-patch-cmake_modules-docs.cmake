--- cmake/modules-docs.cmake.orig	2026-02-18 10:18:48 UTC
+++ cmake/modules-docs.cmake
@@ -130,12 +130,5 @@ function(docs_add_module group_name module_name)
     COMMENT "Generating html documentation for ${module_name}"
   )
   # endif()
-
-  install(
-    FILES ${CMAKE_CURRENT_SOURCE_DIR}/${module_name}/README
-    RENAME README.${module_name}
-    DESTINATION ${CMAKE_INSTALL_DOCDIR}/modules
-    COMPONENT ${group_name}
-  )
   # endif()
 endfunction()
