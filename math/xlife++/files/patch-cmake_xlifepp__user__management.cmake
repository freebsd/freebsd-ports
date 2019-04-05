--- cmake/xlifepp_user_management.cmake.orig	2019-03-30 12:09:49 UTC
+++ cmake/xlifepp_user_management.cmake
@@ -14,12 +14,17 @@ configure_file(${CMAKE_SOURCE_DIR}/etc/templates/CMake
 
 # ask cmake --help to get the list of available generators
 execute_process(COMMAND ${CMAKE_COMMAND} --help OUTPUT_VARIABLE cmake_help)
-string(FIND ${cmake_help} "The following generators are available on this platform:" cmake_generators_start_index)
-math(EXPR cmake_generators_start_index ${cmake_generators_start_index}+57)
+
+# The generators are listed towards the bottom; in CMake 3.14 the
+# header above the list of generators changed, so look for **part**
+# of the header, and then skip the line that includes that header.
+string(FIND ${cmake_help} "The following generators are available on this platform" cmake_generators_start_index)
+math(EXPR cmake_generators_start_index ${cmake_generators_start_index})
 string(SUBSTRING ${cmake_help} ${cmake_generators_start_index} -1 cmake_generators)
 file(WRITE ${CMAKE_BINARY_DIR}/cmake_generators.txt ${cmake_generators})
 file(STRINGS ${CMAKE_BINARY_DIR}/cmake_generators.txt cmake_generator_list)
 file(REMOVE ${CMAKE_BINARY_DIR}/cmake_generators.txt)
+list(REMOVE_AT cmake_generator_list 0)  # First line, still says "The following..."
 list(LENGTH cmake_generator_list nbgeneratorlines)
 math(EXPR nbgeneratorlinesM1 ${nbgeneratorlines}-1)
 
@@ -122,6 +127,12 @@ set(isArch "0")
 foreach (i RANGE ${nbgeneratorlinesM1})
   list(GET cmake_generator_list ${i} line)
   if (NOT ${line} STREQUAL "")
+    # In CMake 3.14, "* " marks the default generator at beginning of line
+    string(SUBSTRING ${line} 0 2 marker)
+    if ("* " STREQUAL "${marker}")
+      string(SUBSTRING ${line} 2 -1 line)
+    endif()
+
     string(FIND ${line} = EQUALINDEX)
     string(STRIP ${line} buffer)
     string(SUBSTRING ${buffer} 0 1 firstcharacter)
