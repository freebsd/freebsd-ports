--- cmake/FindDHT.cmake.orig	2018-07-08 18:11:40 UTC
+++ cmake/FindDHT.cmake
@@ -15,6 +15,10 @@ endif()
 find_path(DHT_INCLUDE_DIR NAMES dht/dht.h HINTS ${_DHT_INCLUDEDIR})
 find_library(DHT_LIBRARY NAMES dht HINTS ${_DHT_LIBDIR})
 
+if (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  set(DHT_INCLUDE_DIR /usr/local/lib)
+endif()
+
 set(DHT_INCLUDE_DIRS ${DHT_INCLUDE_DIR})
 set(DHT_LIBRARIES ${DHT_LIBRARY})
