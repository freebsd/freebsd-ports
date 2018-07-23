--- cmake/find_stp.cmake.orig	2018-07-12 22:25:49 UTC
+++ cmake/find_stp.cmake
@@ -13,6 +13,8 @@
 # is displayed in `ccmake` and `cmake-gui`.
 set(STP_DIR "" CACHE PATH "Path to directory containing STPConfig.cmake")
 find_package(STP CONFIG)
+SET(STP_STATIC_LIBRARY ${FREEBSD_STP_STATIC_LIBRARY})
+MESSAGE("YURI STP_STATIC_LIBRARY=${STP_STATIC_LIBRARY}")
 
 # Set the default so that if the following is true:
 # * STP was found
