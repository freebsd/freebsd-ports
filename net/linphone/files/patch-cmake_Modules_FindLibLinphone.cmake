--- cmake/Modules/FindLibLinphone.cmake.orig	2026-07-15 12:43:54 UTC
+++ cmake/Modules/FindLibLinphone.cmake
@@ -27,7 +27,7 @@ if(NOT TARGET liblinphone)
 if(NOT TARGET liblinphone)
     set(EXPORT_PATH ${LINPHONE_OUTPUT_DIR})
     include(GNUInstallDirs)
-    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/linphone/cmake/linphoneTargets.cmake)
+    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/LibLinphone/cmake/LibLinphoneConfig.cmake)
 endif()
 
 set(_LibLinphone_REQUIRED_VARS LibLinphone_TARGET LibLinphone_PLUGINS_DIR)
@@ -35,7 +35,9 @@ if(TARGET liblinphone)
 
 if(TARGET liblinphone)
 	set(LibLinphone_TARGET liblinphone)
-	get_target_property(LibLinphone_PLUGINS_DIR ${LibLinphone_TARGET} LIBLINPHONE_PLUGINS_DIR)
+	if(NOT LibLinphone_PLUGINS_DIR)
+		get_target_property(LibLinphone_PLUGINS_DIR ${LibLinphone_TARGET} LIBLINPHONE_PLUGINS_DIR)
+	endif()
 endif()
 
 include(FindPackageHandleStandardArgs)
