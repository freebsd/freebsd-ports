--- source/cmake/Findsvthevc.cmake	2020-05-29 17:39:35.000000000 +0000
+++ source/cmake/Findsvthevc.cmake	2020-08-07 02:26:55.307048000 +0000
@@ -39,9 +39,5 @@
         set(SVT_VERSION_PATCHLEVEL ${CMAKE_MATCH_1})
 
-        if(NOT ${SVT_VERSION_MAJOR} EQUAL "1" OR NOT ${SVT_VERSION_MINOR} EQUAL "4" OR NOT ${SVT_VERSION_PATCHLEVEL} EQUAL "1")
-            message (SEND_ERROR "-- Found SVT-HEVC Lib Version: ${SVT_VERSION_MAJOR}.${SVT_VERSION_MINOR}.${SVT_VERSION_PATCHLEVEL} which doesn't match the required version: ${SVT_VERSION_MAJOR_REQUIRED}.${SVT_VERSION_MINOR_REQUIRED}.${SVT_VERSION_PATCHLEVEL_REQUIRED}; Aborting configure  ")
-        else()
-            message(STATUS "-- Found SVT-HEVC Lib Version: ${SVT_VERSION_MAJOR}.${SVT_VERSION_MINOR}.${SVT_VERSION_PATCHLEVEL}")
-        endif()
+        message(STATUS "-- Found SVT-HEVC Lib Version: ${SVT_VERSION_MAJOR}.${SVT_VERSION_MINOR}.${SVT_VERSION_PATCHLEVEL}")
     else()
         message (SEND_ERROR "-- Required version of SVT-HEVC Lib: ${SVT_VERSION_MAJOR_REQUIRED}.${SVT_VERSION_MINOR_REQUIRED}.${SVT_VERSION_PATCHLEVEL_REQUIRED}; Aborting configure  ")
