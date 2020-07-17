--- cmake/Version.cmake.orig	2020-07-14 17:37:45 UTC
+++ cmake/Version.cmake
@@ -70,7 +70,6 @@ else()
     set (BARRIER_BUILD_NUMBER 1)
 endif()
 
-string (TIMESTAMP BARRIER_BUILD_DATE "%Y%m%d" UTC)
 set (BARRIER_SNAPSHOT_INFO ".${BARRIER_VERSION_STAGE}.${BARRIER_REVISION}")
 
 if (BARRIER_VERSION_STAGE STREQUAL "snapshot")
