-- Change BUILD_BYPRODUCTS condition from LINUX to NOT WIN32 so that
-- FreeBSD is also included. On FreeBSD, LINUX is set to TRUE (UNIX AND NOT APPLE),
-- but the intent is to include all non-Windows Unix systems.
--- cmake/external/onednn.cmake.orig	2026-06-19 08:44:32 UTC
+++ cmake/external/onednn.cmake
@@ -70,7 +70,7 @@ endif()
       CACHE FILEPATH "oneDNN library." FORCE)
 endif()
 
-if(LINUX)
+if(NOT WIN32)
   set(BUILD_BYPRODUCTS_ARGS ${ONEDNN_LIB})
 else()
   set(BUILD_BYPRODUCTS_ARGS "")
