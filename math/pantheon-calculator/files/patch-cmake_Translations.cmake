--- cmake/Translations.cmake.orig	2016-09-20 11:55:41 UTC
+++ cmake/Translations.cmake
@@ -91,9 +91,7 @@ macro (configure_file_translation SOURCE
     set(EXTRA_PO_DIR ${PO_DIR}/extra/)
     get_filename_component(EXTRA_PO_DIR ${EXTRA_PO_DIR} ABSOLUTE)
 
-    # Intltool can't create a new directory.
-    get_filename_component(SOURCE_DIRECTORY ${SOURCE} DIRECTORY)
-    file(MAKE_DIRECTORY ${SOURCE_DIRECTORY})
+    get_filename_component(TARGET ${SOURCE} NAME)
 
     set (INTLTOOL_FLAG "")
     if (${SOURCE} MATCHES ".desktop")
@@ -103,7 +101,7 @@ macro (configure_file_translation SOURCE
     elseif (${SOURCE} MATCHES ".xml")
         set (INTLTOOL_FLAG "--xml-style")
     endif ()
-    execute_process (WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMMAND ${INTLTOOL_MERGE_EXECUTABLE} --quiet ${INTLTOOL_FLAG} ${EXTRA_PO_DIR} ${SOURCE} ${RESULT})
+    add_custom_target ("${TARGET}" ALL ${INTLTOOL_MERGE_EXECUTABLE} --quiet ${INTLTOOL_FLAG} ${EXTRA_PO_DIR} ${SOURCE} ${RESULT})
 endmacro ()
 
 macro (add_translations_catalog NLS_PACKAGE)
