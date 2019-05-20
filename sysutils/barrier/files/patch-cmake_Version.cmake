--- cmake/Version.cmake.orig	2019-05-16 15:32:09 UTC
+++ cmake/Version.cmake
@@ -69,7 +69,6 @@ else()
     set (BARRIER_BUILD_NUMBER 1)
 endif()
 
-string (TIMESTAMP BARRIER_BUILD_DATE "%Y%m%d" UTC)
 set (BARRIER_SNAPSHOT_INFO ".${BARRIER_VERSION_STAGE}.${BARRIER_REVISION}")
 
 if (BARRIER_VERSION_STAGE STREQUAL "snapshot")
