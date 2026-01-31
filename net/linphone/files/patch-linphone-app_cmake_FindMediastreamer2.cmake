--- linphone-app/cmake/FindMediastreamer2.cmake.orig	2025-11-12 12:55:13 UTC
+++ linphone-app/cmake/FindMediastreamer2.cmake
@@ -29,7 +29,8 @@ if(NOT TARGET mediastreamer2)
 if(NOT TARGET mediastreamer2)
     set(EXPORT_PATH ${LINPHONE_OUTPUT_DIR})
     include(GNUInstallDirs)
-    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/Mediastreamer2/cmake/Mediastreamer2Targets.cmake)
+    # include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/Mediastreamer2/cmake/Mediastreamer2Targets.cmake)
+    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/Mediastreamer2/cmake/Mediastreamer2Config.cmake)
 endif()
 
 set(_Mediastreamer2_REQUIRED_VARS Mediastreamer2_TARGET Mediastreamer2_PLUGINS_DIR)
@@ -40,10 +41,10 @@ endif()
 	get_target_property(Mediastreamer2_PLUGINS_DIR ${Mediastreamer2_TARGET} MS2_PLUGINS_DIR)
 endif()
 
-include(FindPackageHandleStandardArgs)
-find_package_handle_standard_args(Mediastreamer2
-	REQUIRED_VARS ${_Mediastreamer2_REQUIRED_VARS}
-	HANDLE_COMPONENTS
-)
-mark_as_advanced(${_Mediastreamer2_CACHE_VARS})
+#include(FindPackageHandleStandardArgs)
+#find_package_handle_standard_args(Mediastreamer2
+#	REQUIRED_VARS ${_Mediastreamer2_REQUIRED_VARS}
+#	HANDLE_COMPONENTS
+#)
+#mark_as_advanced(${_Mediastreamer2_CACHE_VARS})
 
