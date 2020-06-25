--- cmake/compiler-specifics.cmake.orig	2020-02-09 22:05:19 UTC
+++ cmake/compiler-specifics.cmake
@@ -15,7 +15,8 @@ endif()
 # use native arch (ie, activate things like SSE)
 if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
   # cannot use add_definitions() here because it does not work with check-sse3.cmake
-  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
+  # 20200624 disable this for FreeBSD package building machines.
+  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
 endif()
 
 # set default warning flags for OGDF and tests
