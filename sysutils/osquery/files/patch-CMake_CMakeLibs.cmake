--- CMake/CMakeLibs.cmake.orig	2015-05-05 00:16:41 UTC
+++ CMake/CMakeLibs.cmake
@@ -15,7 +15,7 @@ endmacro(SET_OSQUERY_COMPILE)
 
 macro(ADD_OSQUERY_PYTHON_TEST TEST_NAME SOURCE)
   add_test(NAME python_${TEST_NAME}
-    COMMAND python "${CMAKE_SOURCE_DIR}/tools/tests/${SOURCE}" --build "${CMAKE_BINARY_DIR}"
+    COMMAND python2 "${CMAKE_SOURCE_DIR}/tools/tests/${SOURCE}" --build "${CMAKE_BINARY_DIR}"
     WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/tools/tests/")
 endmacro(ADD_OSQUERY_PYTHON_TEST)
 
@@ -30,7 +30,7 @@ endmacro(ADD_OSQUERY_LINK)
 
 macro(ADD_OSQUERY_LINK_INTERNAL LINK LINK_PATHS LINK_SET)
   if(NOT "${LINK}" MATCHES "(^[-/].*)")
-    find_library("${LINK}_library" NAMES "lib${LINK}.a" "${LINK}" ${LINK_PATHS})
+      find_library("${LINK}_library" NAMES "${LINK}" "lib${LINK}" ${LINK_PATHS})
     message("-- Found library dependency ${${LINK}_library}")
     if("${${LINK}_library}" STREQUAL "${${LINK}_library}-NOTFOUND")
       string(ASCII 27 Esc)
@@ -105,7 +105,6 @@ endmacro(ADD_OSQUERY_EXTENSION)
 
 macro(ADD_OSQUERY_MODULE TARGET)
   add_library(${TARGET} SHARED ${ARGN})
-  target_link_libraries(${TARGET} dl)
   add_dependencies(${TARGET} libglog libosquery)
   if(APPLE)
     target_link_libraries(${TARGET} "-undefined dynamic_lookup")
@@ -182,7 +181,7 @@ macro(GENERATE_TABLE TABLE_FILE NAME BAS
   GET_GENERATION_DEPS(${BASE_PATH})
   add_custom_command(
     OUTPUT "${TABLE_FILE_GEN}"
-    COMMAND python "${BASE_PATH}/tools/codegen/gentable.py"
+    COMMAND python2 "${BASE_PATH}/tools/codegen/gentable.py"
       "${TABLE_FILE}" "${TABLE_FILE_GEN}" "$ENV{DISABLE_BLACKLIST}"
     DEPENDS ${TABLE_FILE} ${GENERATION_DEPENDENCIES}
     WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
@@ -207,7 +206,7 @@ macro(AMALGAMATE BASE_PATH NAME OUTPUT)
   # Append all of the code to a single amalgamation.
   add_custom_command(
     OUTPUT "${CMAKE_BINARY_DIR}/generated/${NAME}_amalgamation.cpp"
-    COMMAND python "${BASE_PATH}/tools/codegen/amalgamate.py"
+    COMMAND python2 "${BASE_PATH}/tools/codegen/amalgamate.py"
       "${BASE_PATH}/osquery/tables/" "${CMAKE_BINARY_DIR}/generated" "${NAME}"
     DEPENDS ${GENERATED_TARGETS} ${GENERATION_DEPENDENCIES}
     WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
