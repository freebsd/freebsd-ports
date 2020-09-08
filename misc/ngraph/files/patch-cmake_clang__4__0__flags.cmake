--- cmake/clang_4_0_flags.cmake.orig	2020-09-08 10:11:48 UTC
+++ cmake/clang_4_0_flags.cmake
@@ -17,7 +17,6 @@
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=inconsistent-missing-override")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=comment")
-set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")
 if(NGRAPH_STRICT_ERROR_CHECK)
     # These flags are for clang-8
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")
