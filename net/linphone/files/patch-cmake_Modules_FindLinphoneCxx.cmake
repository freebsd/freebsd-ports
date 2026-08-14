--- cmake/Modules/FindLinphoneCxx.cmake.orig	2026-07-15 12:43:54 UTC
+++ cmake/Modules/FindLinphoneCxx.cmake
@@ -26,7 +26,7 @@ if(NOT TARGET liblinphone++)
 if(NOT TARGET liblinphone++)
     set(EXPORT_PATH ${LINPHONE_OUTPUT_DIR})
     include(GNUInstallDirs)
-    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/LinphoneCxx/cmake/LinphoneCxxTargets.cmake)
+    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/LinphoneCxx/cmake/LinphoneCxxConfig.cmake)
 endif()
 
 set(_LinphoneCxx_REQUIRED_VARS LinphoneCxx_TARGET)
