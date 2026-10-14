--- cmake/QtToolchainHelpers.cmake.orig	2026-08-11 12:42:19 UTC
+++ cmake/QtToolchainHelpers.cmake
@@ -55,6 +55,8 @@ function(get_gn_arch result arch)
         set(${result} "mips64el" PARENT_SCOPE)
     elseif(arch STREQUAL "riscv64")
         set(${result} "riscv64" PARENT_SCOPE)
+    elseif(arch STREQUAL "power64")
+        set(${result} "ppc64" PARENT_SCOPE)
     else()
         message(FATAL_ERROR "Unknown architecture: ${arch}")
     endif()
@@ -95,6 +97,8 @@ function(get_gn_os result)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
         set(${result} "ios" PARENT_SCOPE)
+    elseif(FREEBSD)
+        set(${result} "freebsd" PARENT_SCOPE)
     else()
         message(DEBUG "Unrecognized OS")
     endif()
@@ -492,7 +496,7 @@ macro(append_compiler_linker_sdk_setup)
         )
     endif()
     get_gn_arch(cpu ${TEST_architecture_arch})
-    if(LINUX AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
+    if((LINUX OR FREEBSD) AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
 
         extend_gn_list_cflag(gnArgArg
             ARG arm_tune
@@ -601,7 +605,7 @@ macro(append_toolchain_setup)
         endif()
         unset(host_cpu)
         unset(target_cpu)
-    elseif(LINUX)
+    elseif(LINUX OR FREEBSD)
         get_gn_arch(cpu ${TEST_architecture_arch})
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
