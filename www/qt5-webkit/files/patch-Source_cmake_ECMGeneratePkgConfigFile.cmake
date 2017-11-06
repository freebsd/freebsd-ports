--- Source/cmake/ECMGeneratePkgConfigFile.cmake.orig	2017-06-02 18:33:03 UTC
+++ Source/cmake/ECMGeneratePkgConfigFile.cmake
@@ -83,7 +83,7 @@
 
 function(ECM_GENERATE_PKGCONFIG_FILE)
   set(options INSTALL)
-  set(oneValueArgs BASE_NAME LIB_NAME FILENAME_VAR INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)
+  set(oneValueArgs BASE_NAME LIB_NAME FILENAME_VAR INCLUDE_INSTALL_DIR LIB_INSTALL_DIR DESCRIPTION)
   set(multiValueArgs DEPS DEFINES)
 
   cmake_parse_arguments(EGPF "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
@@ -119,6 +119,9 @@ function(ECM_GENERATE_PKGCONFIG_FILE)
           set(EGPF_LIB_INSTALL_DIR "lib")
       endif()
   endif()
+  if(NOT EGPF_DESCRIPTION)
+    message(FATAL_ERROR "Required argument DESCRIPTION missing in ECM_GENERATE_PKGCONFIG_FILE() call")
+  endif()
 
   set(PKGCONFIG_TARGET_BASENAME ${EGPF_BASE_NAME})
   set(PKGCONFIG_TARGET_LIBNAME ${EGPF_LIB_NAME})
@@ -148,6 +151,7 @@ function(ECM_GENERATE_PKGCONFIG_FILE)
   file(WRITE ${PKGCONFIG_FILENAME}
 "
 Name: ${PKGCONFIG_TARGET_LIBNAME}
+Description: ${EGPF_DESCRIPTION}
 Version: ${PROJECT_VERSION}
 Libs: -L${CMAKE_INSTALL_PREFIX}/${EGPF_LIB_INSTALL_DIR} -l${PKGCONFIG_TARGET_LIBNAME}
 Cflags: ${PKGCONFIG_TARGET_INCLUDES} ${PKGCONFIG_TARGET_DEFINES}
@@ -156,7 +160,7 @@ Requires: ${PKGCONFIG_TARGET_DEPS}
   )
 
   if(EGPF_INSTALL)
-    set(ECM_PKGCONFIG_INSTALL_DIR "${EGPF_LIB_INSTALL_DIR}/pkgconfig" CACHE PATH "The directory where pkgconfig will be installed to.")
+    set(ECM_PKGCONFIG_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig" CACHE PATH "The directory where pkgconfig will be installed to.")
     install(FILES ${PKGCONFIG_FILENAME} DESTINATION ${ECM_PKGCONFIG_INSTALL_DIR})
   endif()
 endfunction()
