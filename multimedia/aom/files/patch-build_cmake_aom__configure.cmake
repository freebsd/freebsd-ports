- FreeBSD and NetBSD powerpc* targets don't abbreviate to ppc*
- ARM uses compiler intrinsics, so don't require GNU as

--- build/cmake/aom_configure.cmake.orig	2024-08-27 18:17:57 UTC
+++ build/cmake/aom_configure.cmake
@@ -73,7 +73,7 @@ if(NOT AOM_TARGET_CPU)
     set(AOM_TARGET_CPU "${cpu_lowercase}")
   elseif(cpu_lowercase MATCHES "aarch64")
     set(AOM_TARGET_CPU "arm64")
-  elseif(cpu_lowercase MATCHES "^ppc")
+  elseif(cpu_lowercase MATCHES "^ppc|^powerpc")
     set(AOM_TARGET_CPU "ppc")
   else()
     message(WARNING "The architecture ${CMAKE_SYSTEM_PROCESSOR} is not "
@@ -182,35 +182,6 @@ if(AOM_TARGET_CPU STREQUAL "x86" OR AOM_TARGET_CPU STR
         "your cmake command line.")
   endif()
   string(STRIP "${AOM_AS_FLAGS}" AOM_AS_FLAGS)
-elseif(AOM_TARGET_CPU MATCHES "arm")
-  if(AOM_TARGET_SYSTEM STREQUAL "Darwin")
-    if(NOT CMAKE_ASM_COMPILER)
-      set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
-    endif()
-    set(AOM_AS_FLAGS -arch ${AOM_TARGET_CPU} -isysroot ${CMAKE_OSX_SYSROOT})
-  elseif(AOM_TARGET_SYSTEM STREQUAL "Windows")
-    if(NOT CMAKE_ASM_COMPILER)
-      set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER} "-c -mimplicit-it=always")
-    endif()
-  else()
-    if(NOT CMAKE_ASM_COMPILER)
-      set(CMAKE_ASM_COMPILER as)
-    endif()
-  endif()
-  include(CheckLanguage)
-  check_language(ASM)
-  if(NOT CMAKE_ASM_COMPILER)
-    message(
-      FATAL_ERROR
-        "Unable to find assembler and optimizations are enabled."
-        "Searched for ${CMAKE_ASM_COMPILER}. Install it, add it to your path,"
-        "or set the assembler directly by adding "
-        "-DCMAKE_ASM_COMPILER=<assembler path> to your CMake command line."
-        "To build without optimizations, add -DAOM_TARGET_CPU=generic to your "
-        "cmake command line.")
-  endif()
-  enable_language(ASM)
-  string(STRIP "${AOM_AS_FLAGS}" AOM_AS_FLAGS)
 endif()
 
 if(CONFIG_ANALYZER)
