- FreeBSD and NetBSD powerpc* targets don't abbreviate to ppc*
- ARM uses compiler intrinsics, so don't require GNU as

--- build/cmake/aom_configure.cmake.orig	2021-02-23 19:51:03 UTC
+++ build/cmake/aom_configure.cmake
@@ -71,7 +71,7 @@ if(NOT AOM_TARGET_CPU)
     set(AOM_TARGET_CPU "${cpu_lowercase}")
   elseif(cpu_lowercase MATCHES "aarch64")
     set(AOM_TARGET_CPU "arm64")
-  elseif(cpu_lowercase MATCHES "^ppc")
+  elseif(cpu_lowercase MATCHES "^ppc|^powerpc")
     set(AOM_TARGET_CPU "ppc")
   else()
     message(WARNING "The architecture ${CMAKE_SYSTEM_PROCESSOR} is not "
@@ -159,17 +159,6 @@ elseif(AOM_TARGET_CPU MATCHES "arm")
     if(NOT AS_EXECUTABLE)
       set(AS_EXECUTABLE as)
     endif()
-  endif()
-  find_program(as_executable_found ${AS_EXECUTABLE})
-  if(NOT as_executable_found)
-    message(
-      FATAL_ERROR
-        "Unable to find assembler and optimizations are enabled."
-        "Searched for ${AS_EXECUTABLE}. Install it, add it to your path, or "
-        "set the assembler directly by adding -DAS_EXECUTABLE=<assembler path> "
-        "to your CMake command line."
-        "To build without optimizations, add -DAOM_TARGET_CPU=generic to your "
-        "cmake command line.")
   endif()
   string(STRIP "${AOM_AS_FLAGS}" AOM_AS_FLAGS)
 endif()
