- uname -p returns amd64 on FreeBSD/OpenBSD but x86_64 on DragonFly/NetBSD
- Automatically fall back to generic without forcing downstream to maintain whitelist
- More ELF platforms can use GNU assembler on non-x86

--- build/cmake/aom_configure.cmake.orig	2018-06-25 14:54:59 UTC
+++ build/cmake/aom_configure.cmake
@@ -51,6 +51,7 @@ endforeach()
 # Detect target CPU.
 if(NOT AOM_TARGET_CPU)
   if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64" OR
+     "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "amd64" OR
      "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
     if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
       set(AOM_TARGET_CPU "x86")
@@ -122,10 +123,8 @@ else()
 endif()
 
 if(NOT "${AOM_SUPPORTED_CPU_TARGETS}" MATCHES "${AOM_TARGET_CPU}")
-  message(FATAL_ERROR
-            "No RTCD support for ${AOM_TARGET_CPU}. Create it, or "
-            "add -DAOM_TARGET_CPU=generic to your cmake command line for a "
-            "generic build of libaom and tools.")
+  message(WARNING "No RTCD support for ${AOM_TARGET_CPU}. Assuming generic.")
+  set(AOM_TARGET_CPU generic)
 endif()
 
 if("${AOM_TARGET_CPU}" STREQUAL "x86" OR "${AOM_TARGET_CPU}" STREQUAL "x86_64")
@@ -151,20 +150,15 @@ elseif("${AOM_TARGET_CPU}" MATCHES "arm")
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
 
