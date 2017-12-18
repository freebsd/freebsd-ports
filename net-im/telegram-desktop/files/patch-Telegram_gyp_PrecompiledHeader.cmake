--- Telegram/gyp/PrecompiledHeader.cmake.orig	2017-09-05 17:38:38 UTC
+++ Telegram/gyp/PrecompiledHeader.cmake
@@ -79,7 +79,7 @@ function(export_all_flags _filename _sou
 endfunction()
 
 function(add_precompiled_header _target _input)
-  if(CMAKE_COMPILER_IS_GNUCXX)
+  if(CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
     get_filename_component(_name ${_input} NAME)
     set(_pch_header "${CMAKE_CURRENT_SOURCE_DIR}/${_input}")
     set(_pch_binary_dir "${CMAKE_CURRENT_BINARY_DIR}/${_target}_pch")
@@ -112,7 +112,7 @@ function(add_precompiled_header _target 
       set(_compiler_FLAGS "@${_pch_c_flags_file}")
       add_custom_command(
         OUTPUT "${_output_c}"
-        COMMAND "${CMAKE_C_COMPILER}" ${_compiler_FLAGS} -x c-header -o "${_output_c}" -c "${_pchfile}"
+        COMMAND "${CMAKE_C_COMPILER}" "$(C_DEFINES)" "$(C_INCLUDES)" "$(C_FLAGS)" -x c-header -o "${_output_c}" -c "${_pchfile}"
         DEPENDS "${_pchfile}" "${_pch_c_flags_file}"
         IMPLICIT_DEPENDS C "${_pch_header}"
         COMMENT "Precompiling ${_name} for ${_target} (C)")
@@ -123,7 +123,7 @@ function(add_precompiled_header _target 
       set(_compiler_FLAGS "@${_pch_cpp_flags_file}")
       add_custom_command(
         OUTPUT "${_output_cxx}"
-        COMMAND "${CMAKE_CXX_COMPILER}" ${_compiler_FLAGS} -x c++-header -o "${_output_cxx}" -c "${_pchfile}"
+        COMMAND "${CMAKE_CXX_COMPILER}" "$(CXX_DEFINES)" "$(CXX_INCLUDES)" "$(CXX_FLAGS)" -x c++-header -o "${_output_cxx}" -c "${_pchfile}"
         DEPENDS "${_pchfile}" "${_pch_cpp_flags_file}"
         IMPLICIT_DEPENDS CXX "${_pch_header}"
         COMMENT "Precompiling ${_name} for ${_target} (C++)")
@@ -161,5 +161,5 @@ function(add_precompiled_header _target 
           OBJECT_DEPENDS "${_object_depends}")
       endif()
     endforeach()
-  endif(CMAKE_COMPILER_IS_GNUCXX)
+  endif(CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
 endfunction()
