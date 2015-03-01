--- project/cmake/scripts/common/prepare-env.cmake.orig	2014-12-19 08:42:16.000000000 +0100
+++ project/cmake/scripts/common/prepare-env.cmake	2014-12-21 20:51:17.000000000 +0100
@@ -45,12 +45,12 @@
 get_filename_component(prefix "${DEPENDS_PATH}" ABSOLUTE)
 
 # generate the proper kodi-config.cmake file
-configure_file(${APP_ROOT}/project/cmake/kodi-config.cmake.in ${KODI_LIB_DIR}/kodi-config.cmake @ONLY)
+#configure_file(${APP_ROOT}/project/cmake/kodi-config.cmake.in ${KODI_LIB_DIR}/kodi-config.cmake @ONLY)
 # copy cmake helpers to lib/kodi
-file(COPY ${APP_ROOT}/project/cmake/scripts/common/addon-helpers.cmake ${APP_ROOT}/project/cmake/scripts/common/addoptions.cmake DESTINATION ${KODI_LIB_DIR})
+#file(COPY ${APP_ROOT}/project/cmake/scripts/common/addon-helpers.cmake ${APP_ROOT}/project/cmake/scripts/common/addoptions.cmake DESTINATION ${KODI_LIB_DIR})
 
 # generate xbmc-config.cmake for backwards compatibility to xbmc
-configure_file(${APP_ROOT}/project/cmake/xbmc-config.cmake.in ${XBMC_LIB_DIR}/xbmc-config.cmake @ONLY)
+#configure_file(${APP_ROOT}/project/cmake/xbmc-config.cmake.in ${XBMC_LIB_DIR}/xbmc-config.cmake @ONLY)
 
 ### copy all the addon binding header files to include/kodi
 # parse addon-bindings.mk to get the list of header files to copy
@@ -61,17 +61,6 @@
   string(REPLACE "+=" ";" binding "${binding}")
   list(GET binding 1 header)
   # copy the header file to include/kodi
-  file(COPY ${APP_ROOT}/${header} DESTINATION ${KODI_INCLUDE_DIR})
+  #file(COPY ${APP_ROOT}/${header} DESTINATION ${KODI_INCLUDE_DIR})
 
-  # auto-generate header files for backwards comaptibility to xbmc with deprecation warning
-  get_filename_component(headerfile ${header} NAME)
-  file(WRITE ${XBMC_INCLUDE_DIR}/${headerfile}
-"#pragma once
-#define DEPRECATION_WARNING \"Including xbmc/${headerfile} has been deprecated, please use kodi/${headerfile}\"
-#ifdef _MSC_VER
-  #pragma message(\"WARNING: \" DEPRECATION_WARNING)
-#else
-  #warning DEPRECATION_WARNING
-#endif
-#include \"kodi/${headerfile}\"")
 endforeach()
\ No newline at end of file
