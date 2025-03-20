--- cmake/modules-docs.cmake.orig	2025-01-29 11:36:50 UTC
+++ cmake/modules-docs.cmake
@@ -171,12 +171,6 @@ function(docs_add_module module_name)
       COMMENT "Processing target ${module_name}_man")
 
     install(
-      FILES ${CMAKE_CURRENT_SOURCE_DIR}/${module_name}/README
-      RENAME README.${module_name}
-      DESTINATION ${CMAKE_INSTALL_DOCDIR}/modules
-      COMPONENT kamailio_docs)
-
-    install(
       FILES ${CMAKE_CURRENT_SOURCE_DIR}/${module_name}/${module_name}.7
       DESTINATION ${CMAKE_INSTALL_DATADIR}/man/man7
       COMPONENT kamailio_docs
