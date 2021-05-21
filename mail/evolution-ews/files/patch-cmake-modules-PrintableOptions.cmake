commit 6d8f7d303ec319539add2f0ba5331c2dab9d23c7
Author: Milan Crha <mcrha@redhat.com>
Date:   Wed Apr 14 16:58:08 2021 +0200

    PrintableOptions.cmake: Correct variable name comparison
    
    CMake 3.20.1 errors out with:
    
    CMake Error at cmake/modules/PrintableOptions.cmake:38 (message):
       variable name cannot be empty
     Call Stack (most recent call first):
       CMakeLists.txt:152 (add_printable_variable)
    
    Change how the parameter value is compared, to fix it.

diff --git cmake/modules/PrintableOptions.cmake cmake/modules/PrintableOptions.cmake
index ba1c9d0b..339f1da4 100644
--- cmake/modules/PrintableOptions.cmake
+++ cmake/modules/PrintableOptions.cmake
@@ -19,40 +19,40 @@
 #    prints all the build options previously added with the above functions
 
 macro(add_printable_variable_bare _name)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "variable name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	list(APPEND _printable_options ${_name})
 endmacro()
 
 macro(add_printable_option _name _description _default_value)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "option name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	option(${_name} ${_description} ${_default_value})
 	add_printable_variable_bare(${_name})
 endmacro()
 
 macro(add_printable_variable _name _description _default_value)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "variable name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	set(${_name} ${_default_value} CACHE STRING ${_description})
 	add_printable_variable_bare(${_name})
 endmacro()
 
 macro(add_printable_variable_path _name _description _default_value)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "path variable name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	set(${_name} ${_default_value} CACHE PATH ${_description})
 	add_printable_variable_bare(${_name})
 endmacro()
 
 macro(add_printable_variable_filepath _name _description _default_value)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "filepath variable name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	set(${_name} ${_default_value} CACHE FILEPATH ${_description})
 	add_printable_variable_bare(${_name})
 endmacro()
