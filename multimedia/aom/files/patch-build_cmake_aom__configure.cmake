- uname -p returns amd64 on FreeBSD/OpenBSD but x86_64 on DragonFly/NetBSD
- More ELF platforms can use GNU assembler on non-x86

--- build/cmake/aom_configure.cmake.orig	2018-11-16 20:24:20 UTC
+++ build/cmake/aom_configure.cmake
@@ -37,6 +37,7 @@ string(STRIP "${AOM_CMAKE_CONFIG}" AOM_CMAKE_CONFIG)
 # Detect target CPU.
 if(NOT AOM_TARGET_CPU)
   if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64" OR
+     "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "amd64" OR
      "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
     if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
       set(AOM_TARGET_CPU "x86")
@@ -136,20 +137,15 @@ elseif("${AOM_TARGET_CPU}" MATCHES "arm")
   if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
     set(AS_EXECUTABLE as)
     set(AOM_AS_FLAGS -arch ${AOM_TARGET_CPU} -isysroot ${CMAKE_OSX_SYSROOT})
-  elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
-    if(NOT AS_EXECUTABLE)
-      set(AS_EXECUTABLE as)
-    endif()
   elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Windows")
     if(NOT AS_EXECUTABLE)
       set(AS_EXECUTABLE ${CMAKE_C_COMPILER} -c -mimplicit-it=always)
     endif()
+  else()
+    if(NOT AS_EXECUTABLE)
+      set(AS_EXECUTABLE as)
+    endif()
   endif()
-  if(NOT AS_EXECUTABLE)
-    message(FATAL_ERROR
-              "Unknown assembler for: ${AOM_TARGET_CPU}-${AOM_TARGET_SYSTEM}")
-  endif()
-
   string(STRIP "${AOM_AS_FLAGS}" AOM_AS_FLAGS)
 endif()
 
