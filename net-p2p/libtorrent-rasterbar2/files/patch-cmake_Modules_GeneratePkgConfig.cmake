--- cmake/Modules/GeneratePkgConfig.cmake.orig	2020-08-09 10:43:19 UTC
+++ cmake/Modules/GeneratePkgConfig.cmake
@@ -171,6 +171,11 @@ function(generate_and_install_pkg_config_file _target 
 	set(_pkg_config_file_template_filename "${_GeneratePkGConfigDir}/pkg-config.cmake.in")
 
 	# put target and project properties into a file
+	# Avoid things in the CFLAGS -- which can come from INTERFACE_OPTIONS
+	# of dependencies -- that don't work with file(GENERATE). CMake bug 21074
+	string(REPLACE "<COMPILE_LANG_AND_ID:CUDA,NVIDIA>" "<COMPILE_LANGUAGE:CUDA>" _s "${_interface_compile_options}")
+	set(_interface_compile_options "${_s}")
+
 	configure_file("${_GeneratePkGConfigDir}/target-compile-settings.cmake.in"
 		"${_generate_target_dir}/compile-settings.cmake" @ONLY)
 
