Index: cmake/Modules/DefineCompilerFlags.cmake
===================================================================
--- cmake/Modules/DefineCompilerFlags.cmake	(revision 772)
+++ cmake/Modules/DefineCompilerFlags.cmake	(working copy)
@@ -29,11 +29,11 @@
       ERROR_QUIET
       OUTPUT_STRIP_TRAILING_WHITESPACE
     )
+    string(REGEX REPLACE "[\r\n]" " " "${_lfs_CFLAGS}" "${${_lfs_CFLAGS}}")
+
+    add_definitions(${_lfs_CFLAGS})
   endif (CMAKE_SIZEOF_VOID_P MATCHES "8")
 
-  string(REGEX REPLACE "[\r\n]" " " ${_lfs_CFLAGS} "${${_lfs_CFLAGS}}")
-
-  add_definitions(${_lfs_CFLAGS})
   add_definitions(-Wall -Wextra -Wmissing-prototypes -Wdeclaration-after-statement -Wunused)
 
   check_c_compiler_flag("-fstack-protector" WITH_STACK_PROTECTOR)
