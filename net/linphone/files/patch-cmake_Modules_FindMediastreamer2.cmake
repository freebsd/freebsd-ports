--- cmake/Modules/FindMediastreamer2.cmake.orig	2026-07-15 12:43:54 UTC
+++ cmake/Modules/FindMediastreamer2.cmake
@@ -29,7 +29,7 @@ if(NOT TARGET mediastreamer2)
 if(NOT TARGET mediastreamer2)
     set(EXPORT_PATH ${LINPHONE_OUTPUT_DIR})
     include(GNUInstallDirs)
-    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/Mediastreamer2/cmake/Mediastreamer2Targets.cmake)
+    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/Mediastreamer2/cmake/Mediastreamer2Config.cmake)
 endif()
 
 set(_Mediastreamer2_REQUIRED_VARS Mediastreamer2_TARGET Mediastreamer2_PLUGINS_DIR)
@@ -37,7 +37,9 @@ if(TARGET mediastreamer2)
 
 if(TARGET mediastreamer2)
 	set(Mediastreamer2_TARGET mediastreamer2)
-	get_target_property(Mediastreamer2_PLUGINS_DIR ${Mediastreamer2_TARGET} MS2_PLUGINS_DIR)
+	if(NOT Mediastreamer2_PLUGINS_DIR)
+		get_target_property(Mediastreamer2_PLUGINS_DIR ${Mediastreamer2_TARGET} MS2_PLUGINS_DIR)
+	endif()
 endif()
 
 include(FindPackageHandleStandardArgs)
