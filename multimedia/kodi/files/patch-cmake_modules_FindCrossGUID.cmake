--- cmake/modules/FindCrossGUID.cmake.orig	2026-01-19 17:28:39 UTC
+++ cmake/modules/FindCrossGUID.cmake
@@ -76,7 +76,7 @@ if(NOT TARGET ${APP_NAME_LC}::${CMAKE_FIND_PACKAGE_NAM
       add_library(${APP_NAME_LC}::${CMAKE_FIND_PACKAGE_NAME} ALIAS PkgConfig::${${CMAKE_FIND_PACKAGE_NAME}_SEARCH_NAME})
 
       # NEW_CROSSGUID >= 0.2.0 release
-      if(EXISTS "${${${CMAKE_FIND_PACKAGE_NAME}_MODULE}_INCLUDE_DIR}/crossguid/guid.hpp")
+      if(EXISTS "${${${CMAKE_FIND_PACKAGE_NAME}_MODULE}_INCLUDE_DIR}/guid.hpp")
         list(APPEND ${${CMAKE_FIND_PACKAGE_NAME}_MODULE}_COMPILE_DEFINITIONS HAVE_NEW_CROSSGUID)
       endif()
     else()
