--- cmake/modules-docs.cmake.orig	2025-11-06 09:29:38 UTC
+++ cmake/modules-docs.cmake
@@ -157,13 +157,6 @@ function(docs_add_module group_name module_name)
   )
 
   install(
-    FILES ${CMAKE_CURRENT_SOURCE_DIR}/${module_name}/README
-    RENAME README.${module_name}
-    DESTINATION ${CMAKE_INSTALL_DOCDIR}/modules
-    COMPONENT ${group_name}
-  )
-
-  install(
     FILES ${CMAKE_CURRENT_SOURCE_DIR}/${module_name}/${module_name}.7
     DESTINATION ${CMAKE_INSTALL_DATADIR}/man/man7
     COMPONENT ${group_name}
