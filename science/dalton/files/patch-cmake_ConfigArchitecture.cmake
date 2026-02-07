--- cmake/ConfigArchitecture.cmake.orig	2018-11-19 22:33:46 UTC
+++ cmake/ConfigArchitecture.cmake
@@ -14,6 +14,14 @@ if(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBS
     endif()
 endif()
 
+if(${CMAKE_SYSTEM_NAME} MATCHES "Linux|.*BSD|DragonFly")
+    add_definitions(-DSYS_LINUX) # it's easier to just change to SYS_LINUX for now
+    add_definitions(-DSYS_UNIX)
+    if(${CMAKE_HOST_SYSTEM_PROCESSOR} MATCHES "i686")
+        add_definitions(-DARCH32BIT)
+    endif()
+endif()
+
 if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
     add_definitions(-DSYS_DARWIN)
     add_definitions(-DSYS_UNIX)
