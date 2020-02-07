- ARM uses compiler intrinsics, so don't require GNU as

--- build/cmake/aom_configure.cmake.orig	2020-02-07 16:59:05 UTC
+++ build/cmake/aom_configure.cmake
@@ -162,17 +162,6 @@ elseif("${AOM_TARGET_CPU}" MATCHES "arm")
       set(AS_EXECUTABLE as)
     endif()
   endif()
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
-  endif()
   string(STRIP "${AOM_AS_FLAGS}" AOM_AS_FLAGS)
 endif()
 
