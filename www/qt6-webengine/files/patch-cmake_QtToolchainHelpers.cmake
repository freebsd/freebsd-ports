--- cmake/QtToolchainHelpers.cmake.orig	2025-08-15 18:30:00 UTC
+++ cmake/QtToolchainHelpers.cmake
@@ -95,6 +95,8 @@ function(get_gn_os result)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
         set(${result} "ios" PARENT_SCOPE)
+    elseif(FREEBSD)
+        set(${result} "freebsd" PARENT_SCOPE)
     else()
         message(DEBUG "Unrecognized OS")
     endif()
@@ -326,7 +328,7 @@ macro(append_build_type_setup)
 
     extend_gn_list(gnArgArg
         ARGS enable_precompiled_headers
-        CONDITION BUILD_WITH_PCH AND NOT LINUX
+        CONDITION BUILD_WITH_PCH AND NOT LINUX AND NOT FREEBSD
     )
     extend_gn_list(gnArgArg
         ARGS dcheck_always_on
@@ -418,7 +420,7 @@ macro(append_compiler_linker_sdk_setup)
                 use_libcxx=true
             )
         endif()
-        if(DEFINED QT_FEATURE_stdlib_libcpp AND LINUX)
+        if(DEFINED QT_FEATURE_stdlib_libcpp AND (LINUX OR FREEBSD))
             extend_gn_list(gnArgArg ARGS use_libcxx
                 CONDITION QT_FEATURE_stdlib_libcpp
             )
@@ -459,7 +461,7 @@ macro(append_compiler_linker_sdk_setup)
         )
     endif()
     get_gn_arch(cpu ${TEST_architecture_arch})
-    if(LINUX AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
+    if((LINUX OR FREEBSD) AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
 
         extend_gn_list_cflag(gnArgArg
             ARG arm_tune
@@ -568,7 +570,7 @@ macro(append_toolchain_setup)
         endif()
         unset(host_cpu)
         unset(target_cpu)
-    elseif(LINUX)
+    elseif(LINUX OR FREEBSD)
         get_gn_arch(cpu ${TEST_architecture_arch})
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
