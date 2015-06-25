--- builders/cmake/cmake_find_modules/pch_support.cmake.orig	2013-10-01 03:50:34 UTC
+++ builders/cmake/cmake_find_modules/pch_support.cmake
@@ -1,76 +1,6 @@
 #This code is taken from here:
 #http://www.mail-archive.com/cmake@cmake.org/msg04394.html
 
-IF(CMAKE_COMPILER_IS_GNUCXX)
-    EXEC_PROGRAM(
-        ${CMAKE_CXX_COMPILER} 
-        ARGS                    --version 
-        OUTPUT_VARIABLE _compiler_output)
-    STRING(REGEX REPLACE ".* ([0-9]\\.[0-9]\\.[0-9]) .*" "\\1" 
-           gcc_compiler_version ${_compiler_output})
-    #MESSAGE("GCC Version: ${gcc_compiler_version}")
-    IF(gcc_compiler_version MATCHES "4\\.[0-9]\\.[0-9]")
-        MESSAGE(STATUS "We have support for precompiled headers")
-		SET(PCHSupport_FOUND TRUE)
-    ELSE(gcc_compiler_version MATCHES "4\\.[0-9]\\.[0-9]")
-        IF(gcc_compiler_version MATCHES "3\\.4\\.[0-9]")
-			MESSAGE(STATUS "We have support for precompiled headers")
-            SET(PCHSupport_FOUND TRUE)
-        ENDIF(gcc_compiler_version MATCHES "3\\.4\\.[0-9]")
-    ENDIF(gcc_compiler_version MATCHES "4\\.[0-9]\\.[0-9]")
-ENDIF(CMAKE_COMPILER_IS_GNUCXX)
-
 MACRO(ADD_PRECOMPILED_HEADER _targetName _input )
-	#get the file name (no path)
-	GET_FILENAME_COMPONENT(_name ${_input} NAME_WE)
-
-	#locate the file
-	SET(_source "${_input}")
-	
-	#compute the output directory
-	SET(_outdir "${CMAKE_BINARY_DIR}/precompiled.gch/${CMAKE_BUILD_TYPE}.c++")
-
-	#create the output directory
-	MAKE_DIRECTORY(${_outdir})
-
-	#compute the output file
-	SET(_output "${_outdir}/${_name}.gch")
-
-	#get the compiler flags
-	STRING(TOUPPER "CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}" _flags_var_name)
-	SET(_compiler_FLAGS ${CMAKE_CXX_FLAGS} ${${_flags_var_name}})
-
-	#get the list of include directories for the current project and compute the new version of compiler flags by
-	#appinding -I
-	GET_DIRECTORY_PROPERTY(_directory_flags INCLUDE_DIRECTORIES)
-	FOREACH(item ${_directory_flags})
-		LIST(APPEND _compiler_FLAGS "-I${item}")
-	ENDFOREACH(item)
-
-	#get the definitions of the current project and append them as well to the current compiler flags 
-        GET_DIRECTORY_PROPERTY(_directory_flags DEFINITIONS)
-	LIST(APPEND _compiler_FLAGS ${_directory_flags})
-
-	#now split the entire thing
-	SEPARATE_ARGUMENTS(_compiler_FLAGS)
-
-	#compute the new command
-	ADD_CUSTOM_COMMAND(
-		OUTPUT ${_output}
-		COMMAND ${CMAKE_CXX_COMPILER} ${PCH_CXX_FLAGS} ${_compiler_FLAGS} -x c++-header -c -o ${_output} ${_source}
-		DEPENDS ${_source}
-	)
-        
-	#add a new target to the project
-	ADD_CUSTOM_TARGET(${_targetName}_${_name}_gch DEPENDS ${_output})
-	ADD_DEPENDENCIES(${_targetName} ${_targetName}_${_name}_gch)
-
-	EXECUTE_PROCESS(COMMAND ${CMAKE_CXX_COMPILER} --version OUTPUT_VARIABLE _COMPILER_VERSION)
-	STRING(TOLOWER "${_COMPILER_VERSION}" _COMPILER_VERSION)
-	IF(_COMPILER_VERSION MATCHES ".*(clang|llvm).*")
-		SET_TARGET_PROPERTIES(${_targetName} PROPERTIES COMPILE_FLAGS "-include-pch ${_output} -Winvalid-pch")
-	ELSE()
-		SET_TARGET_PROPERTIES(${_targetName} PROPERTIES COMPILE_FLAGS "-I${_outdir} -include ${_name} -Winvalid-pch")
-	ENDIF()
 ENDMACRO(ADD_PRECOMPILED_HEADER)
 
