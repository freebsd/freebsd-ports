--- cmake_support/OST.cmake.orig	2018-02-27 14:29:54 UTC
+++ cmake_support/OST.cmake
@@ -834,7 +834,7 @@ macro(setup_stage)
     check_architecture()
   endif()
   set (ARCH ${CMAKE_NATIVE_ARCH})
-  if ("${ARCH}" MATCHES "64" AND NOT _UBUNTU_LAYOUT)
+  if ("${ARCH}" MATCHES "64" AND NOT _UBUNTU_LAYOUT AND NOT ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
     set(LIB_DIR lib64  )
     set(LIB_STAGE_PATH "${STAGE_DIR}/lib64"  )
   else()
@@ -902,7 +902,7 @@ set(_BOOST_MIN_VERSION 1.31)
 
 macro(setup_boost)
   set (Boost_NO_BOOST_CMAKE TRUE)
-  find_package(Boost ${_BOOST_MIN_VERSION} COMPONENTS python REQUIRED)
+  find_package(Boost ${_BOOST_MIN_VERSION} COMPONENTS ${FREEBSD_BOOST_PYTHON_COMPONENT} REQUIRED)
   set(BOOST_PYTHON_LIBRARIES ${Boost_LIBRARIES})
   set(Boost_LIBRARIES)
   find_package(Boost ${_BOOST_MIN_VERSION}
