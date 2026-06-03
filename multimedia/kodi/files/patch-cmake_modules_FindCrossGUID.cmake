--- cmake/modules/FindCrossGUID.cmake.orig	2026-03-20 17:18:29 UTC
+++ cmake/modules/FindCrossGUID.cmake
@@ -58,7 +58,7 @@ if(NOT TARGET ${APP_NAME_LC}::${CMAKE_FIND_PACKAGE_NAM
       get_target_property(_crossguid_include_dir PkgConfig::${${CMAKE_FIND_PACKAGE_NAME}_SEARCH_NAME} INTERFACE_INCLUDE_DIRECTORIES)
 
       # NEW_CROSSGUID >= 0.2.0 release
-      if(EXISTS "${_crossguid_include_dir}/crossguid/guid.hpp")
+      if(EXISTS "${_crossguid_include_dir}/guid.hpp")
         list(APPEND ${${CMAKE_FIND_PACKAGE_NAME}_MODULE}_COMPILE_DEFINITIONS HAVE_NEW_CROSSGUID)
       endif()
     elseif(TARGET crossguid AND NOT TARGET ${${${CMAKE_FIND_PACKAGE_NAME}_MODULE}_BUILD_NAME})
@@ -67,7 +67,7 @@ if(NOT TARGET ${APP_NAME_LC}::${CMAKE_FIND_PACKAGE_NAM
       get_target_property(_crossguid_include_dir crossguid INTERFACE_INCLUDE_DIRECTORIES)
 
       # NEW_CROSSGUID >= 0.2.0 release
-      if(EXISTS "${_crossguid_include_dir}/crossguid/guid.hpp")
+      if(EXISTS "${_crossguid_include_dir}/guid.hpp")
         list(APPEND ${${CMAKE_FIND_PACKAGE_NAME}_MODULE}_COMPILE_DEFINITIONS HAVE_NEW_CROSSGUID)
       endif()
     else()
