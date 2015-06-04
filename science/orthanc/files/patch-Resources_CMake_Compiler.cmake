--- Resources/CMake/Compiler.cmake.orig	2015-02-12 13:47:38 UTC
+++ Resources/CMake/Compiler.cmake
@@ -4,7 +4,8 @@ if (${CMAKE_COMPILER_IS_GNUCXX})
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -Wno-implicit-function-declaration")  
   # --std=c99 makes libcurl not to compile
   # -pedantic gives a lot of warnings on OpenSSL 
-  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wno-long-long -Wno-variadic-macros")
+  # with -pedantic we failing to build headers from boost, which have comma at the end of enum's
+  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -Wno-variadic-macros")
 
   if (CMAKE_CROSSCOMPILING)
     # http://stackoverflow.com/a/3543845/881731
@@ -79,6 +80,8 @@ elseif (${CMAKE_SYSTEM_NAME} STREQUAL "D
     )
   link_libraries(iconv)
 
+elseif (${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
+  link_libraries(uuid pthread)
 endif()
 
 
