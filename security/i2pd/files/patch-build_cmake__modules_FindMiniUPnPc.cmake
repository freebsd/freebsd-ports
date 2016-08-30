--- build/cmake_modules/FindMiniUPnPc.cmake.orig	2016-08-12 15:07:00 UTC
+++ build/cmake_modules/FindMiniUPnPc.cmake
@@ -1,6 +1,6 @@
 # - Find MINIUPNPC
 
-if(MINIUPNPC_INCLUDE_DIR)
+if(MINIUPNPC_INCLUDE_DIR AND MINIUPNPC_LIBRARY)
    set(MINIUPNPC_FOUND TRUE)
 
 else()
@@ -11,15 +11,18 @@ else()
       $ENV{SystemDrive}
       ${PROJECT_SOURCE_DIR}/../..
       )
-  
-  if(MINIUPNPC_INCLUDE_DIR)
+
+  find_library(MINIUPNPC_LIBRARY miniupnpc)
+
+  if(MINIUPNPC_INCLUDE_DIR AND MINIUPNPC_LIBRARY)
     set(MINIUPNPC_FOUND TRUE)
     message(STATUS "Found MiniUPnP headers: ${MINIUPNPC_INCLUDE_DIR}")
+    message(STATUS "Found MiniUPnP library: ${MINIUPNPC_LIBRARY}")
   else()
     set(MINIUPNPC_FOUND FALSE)
     message(STATUS "MiniUPnP not found.")
   endif()
 
-  mark_as_advanced(MINIUPNPC_INCLUDE_DIR)
+  mark_as_advanced(MINIUPNPC_INCLUDE_DIR MINIUPNPC_LIBRARY)
   
 endif()
