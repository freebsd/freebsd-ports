--- Macros.cmake.orig	2026-03-23 08:45:44 UTC
+++ Macros.cmake
@@ -1,4 +1,4 @@
-include(CheckIncludeFile)
+include(CheckIncludeFiles)
 include(CheckFunctionExists)
 include(CheckLibraryExists)
 include(CheckTypeSize)
@@ -30,7 +30,7 @@ macro(cm_check_include include var)
 endmacro()
 
 macro(cm_check_include include var)
-    check_include_file(${include} ${var})
+    check_include_files("${include}" ${var})
     if(${var})
         set(defines ${defines} "#cmakedefine ${var}\n\n")
     else()
