ELF is also used on Solaris, BSDs, Haiku, Fuchsia, etc.

--- build/cmake/aom_optimization.cmake.orig	2018-06-25 14:54:59 UTC
+++ build/cmake/aom_optimization.cmake
@@ -83,24 +83,20 @@ function(get_asm_obj_format out_format)
   if("${AOM_TARGET_CPU}" STREQUAL "x86_64")
     if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
       set(objformat "macho64")
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
-      set(objformat "elf64")
     elseif("${AOM_TARGET_SYSTEM}" STREQUAL "MSYS" OR "${AOM_TARGET_SYSTEM}"
            STREQUAL "Windows")
       set(objformat "win64")
     else()
-      message(FATAL_ERROR "Unknown obj format: ${AOM_TARGET_SYSTEM}")
+      set(objformat "elf64")
     endif()
   elseif("${AOM_TARGET_CPU}" STREQUAL "x86")
     if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
       set(objformat "macho32")
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
-      set(objformat "elf32")
     elseif("${AOM_TARGET_SYSTEM}" STREQUAL "MSYS" OR "${AOM_TARGET_SYSTEM}"
            STREQUAL "Windows")
       set(objformat "win32")
     else()
-      message(FATAL_ERROR "Unknown obj format: ${AOM_TARGET_SYSTEM}")
+      set(objformat "elf32")
     endif()
   else()
     message(FATAL_ERROR
@@ -171,7 +167,13 @@ function(test_nasm)
         message(FATAL_ERROR
                   "Unsupported nasm: macho32 object format not supported.")
       endif()
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
+    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "MSYS" OR "${AOM_TARGET_SYSTEM}"
+           STREQUAL "Windows")
+      if(NOT "${nasm_helptext}" MATCHES "win32")
+        message(FATAL_ERROR
+                  "Unsupported nasm: win32 object format not supported.")
+      endif()
+    else()
       if(NOT "${nasm_helptext}" MATCHES "elf32")
         message(FATAL_ERROR
                   "Unsupported nasm: elf32 object format not supported.")
@@ -183,7 +185,13 @@ function(test_nasm)
         message(FATAL_ERROR
                   "Unsupported nasm: macho64 object format not supported.")
       endif()
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
+    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "MSYS" OR "${AOM_TARGET_SYSTEM}"
+           STREQUAL "Windows")
+      if(NOT "${nasm_helptext}" MATCHES "win64")
+        message(FATAL_ERROR
+                  "Unsupported nasm: win64 object format not supported.")
+      endif()
+    else()
       if(NOT "${nasm_helptext}" MATCHES "elf64")
         message(FATAL_ERROR
                   "Unsupported nasm: elf64 object format not supported.")
