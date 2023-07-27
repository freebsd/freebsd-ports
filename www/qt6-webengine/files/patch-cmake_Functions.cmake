--- cmake/Functions.cmake.orig	2023-07-07 17:40:32 UTC
+++ cmake/Functions.cmake
@@ -449,7 +449,7 @@ function(add_linker_options target buildDir completeSt
     set(archives_rsp "${buildDir}/${ninjaTarget}_archives.rsp")
     set(libs_rsp "${buildDir}/${ninjaTarget}_libs.rsp")
     set_target_properties(${cmakeTarget} PROPERTIES STATIC_LIBRARY_OPTIONS "@${objects_rsp}")
-    if(LINUX OR ANDROID)
+    if(LINUX OR ANDROID OR FREEBSD)
          get_gn_arch(cpu ${TEST_architecture_arch})
          if(CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm" AND ${config} STREQUAL "Debug")
              target_link_options(${cmakeTarget} PRIVATE "LINKER:--long-plt")
@@ -715,6 +715,8 @@ function(get_gn_os result)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
         set(${result} "ios" PARENT_SCOPE)
+    elseif(FREEBSD)
+        set(${result} "freebsd" PARENT_SCOPE)
     else()
         message(DEBUG "Unrecognized OS")
     endif()
@@ -904,7 +906,7 @@ macro(append_build_type_setup)
 
     extend_gn_list(gnArgArg
         ARGS enable_precompiled_headers
-        CONDITION BUILD_WITH_PCH AND NOT LINUX
+	CONDITION BUILD_WITH_PCH AND NOT (LINUX OR FREEBSD)
     )
     extend_gn_list(gnArgArg
         ARGS dcheck_always_on
@@ -952,7 +954,7 @@ macro(append_compiler_linker_sdk_setup)
                 use_libcxx=true
             )
         endif()
-        if(DEFINED QT_FEATURE_stdlib_libcpp AND LINUX)
+	if(DEFINED QT_FEATURE_stdlib_libcpp AND (LINUX OR FREEBSD))
             extend_gn_list(gnArgArg ARGS use_libcxx
                 CONDITION QT_FEATURE_stdlib_libcpp
             )
@@ -988,7 +990,7 @@ macro(append_compiler_linker_sdk_setup)
         )
     endif()
     get_gn_arch(cpu ${TEST_architecture_arch})
-    if(LINUX AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
+    if((LINUX OR FREEBSD) AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
 
         extend_gn_list_cflag(gnArgArg
             ARG arm_tune
@@ -1055,7 +1057,7 @@ macro(append_toolchain_setup)
 endmacro()
 
 macro(append_toolchain_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
             host_toolchain="${buildDir}/host_toolchain:host"
@@ -1087,7 +1089,7 @@ macro(append_pkg_config_setup)
 
 
 macro(append_pkg_config_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             pkg_config="${PKG_CONFIG_EXECUTABLE}"
             host_pkg_config="${PKG_CONFIG_HOST_EXECUTABLE}"
@@ -1165,6 +1167,20 @@ function(add_gn_build_aritfacts_to_target cmakeTarget 
             set_target_properties(${cmakeTarget} PROPERTIES
                 LINK_DEPENDS ${buildDir}/${config}/${arch}/${ninjaTarget}.stamp
             )
+            # For some reason when the build of QtWebEngine's "convert_dict" is
+            # completed the "convert_dict.stamp" isn't created.
+            #
+            # Work around this issue by creating "convert_dict.stamp" manually.
+            if(${ninjaTarget} STREQUAL "convert_dict")
+                add_custom_command(
+                    POST_BUILD
+                    COMMENT "Add workaround for missing ${ninjaTarget}.stamp file after build"
+                    COMMAND ${CMAKE_COMMAND} -E touch ${buildDir}/${config}/${arch}/${ninjaTarget}.stamp
+                    TARGET ${target}
+                    DEPENDS run_${module}_NinjaDone
+                    USES_TERMINAL
+            )
+            endif()
             if(QT_IS_MACOS_UNIVERSAL)
                 add_intermediate_archive(${target} ${buildDir}/${config}/${arch} ${completeStatic})
             elseif(IOS)
@@ -1291,7 +1307,7 @@ function(check_for_ulimit)
 
 function(check_for_ulimit)
     message("-- Checking 'ulimit -n'")
-    execute_process(COMMAND bash -c "ulimit -n"
+    execute_process(COMMAND sh -c "ulimit -n"
         OUTPUT_VARIABLE ulimitOutput
     )
     string(REGEX MATCHALL "[0-9]+" limit "${ulimitOutput}")
@@ -1300,7 +1316,7 @@ function(check_for_ulimit)
         if(NOT ${CMAKE_VERSION} VERSION_LESS "3.21.0")
             message(" -- Creating linker launcher")
             file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/linker_ulimit.sh
-                CONTENT "#!/bin/bash\nulimit -n 4096\nexec \"$@\""
+                CONTENT "#!/bin/sh\nulimit -n 4096\nexec \"$@\""
                 FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
             )
             set(COIN_BUG_699 ON PARENT_SCOPE)
