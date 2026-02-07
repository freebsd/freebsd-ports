--- src/shared/cmake/MacroCheckGccVisibility.cmake.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/shared/cmake/MacroCheckGccVisibility.cmake	2013-03-27 15:02:55.000000000 -0400
@@ -6,7 +6,7 @@
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
 macro(MACRO_CHECK_GCC_VISIBILITY GccVisibility)
-  if (CMAKE_COMPILER_IS_GNUCXX)
+  if (CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    include(CheckCXXCompilerFlag)
    include(MacroEnsureVersion)
    # visibility support
@@ -43,7 +43,7 @@
 
    if (${GccVisibility} AND GCC_IS_NEWER_THAN_4_1 AND NOT _GCC_COMPILED_WITH_BAD_ALLOCATOR)
       set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
-      set (KDE4_C_FLAGS "${KDE4_C_FLAGS}" "-fvisibility=hidden")
+      set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" "-fvisibility=hidden")
 
       if (GCC_IS_NEWER_THAN_4_2)
           set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
@@ -52,7 +52,7 @@
       set (${GccVisibility} 0)
    endif (${GccVisibility} AND GCC_IS_NEWER_THAN_4_1 AND NOT _GCC_COMPILED_WITH_BAD_ALLOCATOR)
 
-  else (CMAKE_COMPILER_IS_GNUCXX)
+  else (CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
     set(${GccVisibility} FALSE)
-  endif (CMAKE_COMPILER_IS_GNUCXX)
+  endif (CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
 endmacro(MACRO_CHECK_GCC_VISIBILITY)
