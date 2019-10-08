- More ELF platforms can use GNU assembler on non-x86

--- build/cmake/aom_configure.cmake.orig	2019-10-07 23:31:01 UTC
+++ build/cmake/aom_configure.cmake
@@ -154,21 +154,15 @@ elseif("${AOM_TARGET_CPU}" MATCHES "arm")
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
-    message(
-      FATAL_ERROR
-        "Unknown assembler for: ${AOM_TARGET_CPU}-${AOM_TARGET_SYSTEM}")
-  endif()
-
   string(STRIP "${AOM_AS_FLAGS}" AOM_AS_FLAGS)
 endif()
 
