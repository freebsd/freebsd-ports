--- cmake/doc.cmake.orig	2020-02-09 22:05:19 UTC
+++ cmake/doc.cmake
@@ -1,13 +1,12 @@
 # Documentation-related CMake configuration
 
 set(doc_dir "${PROJECT_SOURCE_DIR}/doc")
-set(DOC_INSTALL_DIR "share/doc/libogdf" CACHE PATH "Installation path of OGDF documentation and examples")
+set(DOC_INSTALL_DIR "share/doc/libogdf" CACHE PATH "Installation path of OGDF documentation")
 mark_as_advanced(DOC_INSTALL_DIR)
 
-# installation of examples as documentation
 file(GLOB_RECURSE example_files "${doc_dir}/*.txt" "${doc_dir}/*.bench" "${doc_dir}/*.gml")
-install(DIRECTORY doc/examples
-  DESTINATION ${DOC_INSTALL_DIR}
+install(DIRECTORY doc/examples/
+  DESTINATION ${EXAMPLES_INSTALL_DIR}
   FILES_MATCHING
     PATTERN "*.cpp"
     PATTERN "*.txt"
