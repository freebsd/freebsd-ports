--- cmake-modules/FindNettle.cmake.orig	2022-07-08 18:30:56 UTC
+++ cmake-modules/FindNettle.cmake
@@ -40,12 +40,16 @@ find_library(NETTLE_LIBRARY
         NAMES nettle libnettle
         HINTS ${PC_NETTLE_LIBDIR} ${PC_NETTLE_LIBRARY_DIRS})
 
+find_library(HOGWEED_LIBRARY
+        NAMES hogweed libhogweed
+        HINTS ${PC_NETTLE_LIBDIR} ${PC_NETTLE_LIBRARY_DIRS})
+
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(Nettle
         REQUIRED_VARS NETTLE_LIBRARY NETTLE_INCLUDE_DIR)
 
 if (NETTLE_FOUND)
-    set(NETTLE_LIBRARIES ${NETTLE_LIBRARY})
+    set(NETTLE_LIBRARIES ${NETTLE_LIBRARY} ${HOGWEED_LIBRARY})
     set(NETTLE_INCLUDE_DIRS ${NETTLE_INCLUDE_DIR})
 endif ()
 
