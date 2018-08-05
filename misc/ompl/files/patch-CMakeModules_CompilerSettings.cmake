--- CMakeModules/CompilerSettings.cmake.orig	2018-08-04 19:52:03 UTC
+++ CMakeModules/CompilerSettings.cmake
@@ -21,12 +21,12 @@ if(CMAKE_COMPILER_IS_GNUCXX)
                     -Wno-noexcept-type
                     -Wno-deprecated-declarations)
     # prepend optimizion flag (in case the default setting doesn't include one)
-    set(CMAKE_CXX_FLAGS_RELEASE "-O3 ${CMAKE_CXX_FLAGS_RELEASE}")
+    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
 endif(CMAKE_COMPILER_IS_GNUCXX)
 if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
     add_definitions(-W -Wall -Wextra -Wno-missing-field-initializers -Wno-unused -Wno-unused-parameter -Wno-delete-non-virtual-dtor -Wno-overloaded-virtual -Wno-unknown-pragmas -Qunused-arguments -Wno-deprecated-register -Wno-mismatched-tags -Wno-deprecated-declarations)
     # prepend optimizion flag (in case the default setting doesn't include one)
-    set(CMAKE_CXX_FLAGS_RELEASE "-O3 ${CMAKE_CXX_FLAGS_RELEASE}")
+    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
 endif()
 
 if(MSVC OR MSVC90 OR MSVC10)
@@ -42,7 +42,7 @@ if(IS_ICPC)
     add_definitions(-wd191 -wd411 -wd654 -wd1125 -wd1292 -wd1565 -wd1628 -wd2196)
     set(CMAKE_AR "xiar" CACHE STRING "Intel archiver" FORCE)
     set(CMAKE_CXX_FLAGS "-pthread" CACHE STRING "Default compile flags" FORCE)
-    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG"
+    set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG"
     CACHE STRING "Flags used by the C++ compiler during release builds." FORCE)
     set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g" CACHE STRING
     "Flags used by the C++ compiler during debug builds." FORCE)
