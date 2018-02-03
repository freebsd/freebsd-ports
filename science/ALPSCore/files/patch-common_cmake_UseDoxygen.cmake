--- common/cmake/UseDoxygen.cmake.orig	2018-01-30 05:54:55 UTC
+++ common/cmake/UseDoxygen.cmake
@@ -134,7 +134,7 @@ if(DOXYGEN_FOUND AND DOXYFILE_IN_FOUND)
 
 
 	configure_file("${DOXYFILE_IN}" "${DOXYFILE}" @ONLY)
-        install(DIRECTORY ${DOXYFILE_OUTPUT_DIR}/ DESTINATION share/ALPSCore_doc MESSAGE_NEVER)
+        install(DIRECTORY ${DOXYFILE_OUTPUT_DIR}/ DESTINATION share/doc/ALPSCore MESSAGE_NEVER)
 
 	if(NOT TARGET doc)
 		add_custom_target(doc ALL)
