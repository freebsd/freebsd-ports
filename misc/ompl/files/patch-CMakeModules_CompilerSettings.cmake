--- CMakeModules/CompilerSettings.cmake.orig	2020-06-02 18:39:48 UTC
+++ CMakeModules/CompilerSettings.cmake
@@ -5,12 +5,12 @@ set(CMAKE_CXX_EXTENSIONS OFF)
 if(CMAKE_COMPILER_IS_GNUCXX)
     add_definitions(-W -Wall -Wextra -Wno-system-headers)
     # prepend optimizion flag (in case the default setting doesn't include one)
-    set(CMAKE_CXX_FLAGS_RELEASE "-O3 ${CMAKE_CXX_FLAGS_RELEASE}")
+    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
 endif(CMAKE_COMPILER_IS_GNUCXX)
 if(CMAKE_CXX_COMPILER_ID MATCHES "^(Apple)?Clang$")
     add_definitions(-W -Wall -Wextra -Wno-system-headers)
     # prepend optimizion flag (in case the default setting doesn't include one)
-    set(CMAKE_CXX_FLAGS_RELEASE "-O3 ${CMAKE_CXX_FLAGS_RELEASE}")
+    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
 endif()
 
 if(MSVC)
