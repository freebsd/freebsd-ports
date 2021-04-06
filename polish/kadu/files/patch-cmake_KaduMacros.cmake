--- cmake/KaduMacros.cmake.orig	2021-04-03 20:24:23 UTC
+++ cmake/KaduMacros.cmake
@@ -44,7 +44,8 @@ include_directories (${INJEQT_INCLUDEDIR})
 link_directories (${INJEQT_LIBRARY_DIRS})
 
 set (CMAKE_CXX_FLAGS "-Woverloaded-virtual -Wnon-virtual-dtor ${CMAKE_CXX_FLAGS}")
-set (CMAKE_CXX_STANDARD 14)
+set (CMAKE_CXX_STANDARD 17)
+set (CMAKE_CXX_STANDARD_REQUIRED ON)
 
 if (NOT WIN32)
     set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
