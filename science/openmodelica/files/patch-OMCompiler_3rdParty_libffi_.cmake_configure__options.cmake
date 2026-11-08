--- OMCompiler/3rdParty/libffi/.cmake/configure_options.cmake.orig	2025-10-15 12:39:07 UTC
+++ OMCompiler/3rdParty/libffi/.cmake/configure_options.cmake
@@ -112,6 +112,13 @@ elseif(TARGET_PLATFORM MATCHES ARM.*)
 
     list(APPEND SOURCES_LIST src/arm/ffi.c)
     set(TARGETDIR arm)
+elseif(TARGET_PLATFORM STREQUAL POWERPC)
+    list(APPEND SOURCES_LIST
+        src/powerpc/ffi.c
+        src/powerpc/ffi_linux64.c
+        src/powerpc/linux64.S
+        src/powerpc/linux64_closure.S)
+    set(TARGETDIR powerpc)
 endif()
 
 if(CMAKE_SYSTEM_NAME STREQUAL Darwin AND TARGET_PLATFORM STREQUAL AARCH64)
