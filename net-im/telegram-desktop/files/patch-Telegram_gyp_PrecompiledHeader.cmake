--- Telegram/gyp/PrecompiledHeader.cmake.orig	2019-07-07 13:34:35 UTC
+++ Telegram/gyp/PrecompiledHeader.cmake
@@ -114,7 +114,7 @@ function(add_precompiled_header _target _input)
       set(_compiler_FLAGS "@${_pch_c_flags_file}")
       add_custom_command(
         OUTPUT "${_output_c}"
-        COMMAND "${CMAKE_C_COMPILER}" ${_compiler_FLAGS} -x c-header -o "${_output_c}" -c "${_pchfile}"
+        COMMAND "${CMAKE_C_COMPILER}" "$(C_DEFINES)" "$(C_INCLUDES)" "$(C_FLAGS)" -x c-header -o "${_output_c}" -c "${_pchfile}"
         DEPENDS "${_pchfile}" "${_pch_c_flags_file}"
         IMPLICIT_DEPENDS C "${_pch_header}"
         COMMENT "Precompiling ${_name} for ${_target} (C)")
@@ -125,7 +125,7 @@ function(add_precompiled_header _target _input)
       set(_compiler_FLAGS "@${_pch_cpp_flags_file}")
       add_custom_command(
         OUTPUT "${_output_cxx}"
-        COMMAND "${CMAKE_CXX_COMPILER}" ${_compiler_FLAGS} -x c++-header -o "${_output_cxx}" -c "${_pchfile}"
+        COMMAND "${CMAKE_CXX_COMPILER}" "$(CXX_DEFINES)" "$(CXX_INCLUDES)" "$(CXX_FLAGS)" -x c++-header -o "${_output_cxx}" -c "${_pchfile}"
         DEPENDS "${_pchfile}" "${_pch_cpp_flags_file}"
         IMPLICIT_DEPENDS CXX "${_pch_header}"
         COMMENT "Precompiling header ${_name} for ${_target} (C++)")
