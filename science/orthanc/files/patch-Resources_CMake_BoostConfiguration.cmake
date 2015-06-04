--- Resources/CMake/BoostConfiguration.cmake.orig	2015-02-12 13:47:38 UTC
+++ Resources/CMake/BoostConfiguration.cmake
@@ -56,6 +56,7 @@ if (BOOST_STATIC)
 
   if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR
       ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" OR
+      ${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD" OR
       ${CMAKE_SYSTEM_NAME} STREQUAL "kFreeBSD")
     list(APPEND BOOST_SOURCES
       ${BOOST_SOURCES_DIR}/libs/thread/src/pthread/once.cpp
