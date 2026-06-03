--- linphone-app/cmake/FindQtKeychain.cmake.orig	2025-11-12 12:55:13 UTC
+++ linphone-app/cmake/FindQtKeychain.cmake
@@ -26,23 +26,22 @@ if(NOT TARGET ${QTKEYCHAIN_TARGET_NAME})
 #  QtKeychain_INCLUDE_DIRS - the linphonecxx include directory
 #  QtKeychain_LIBRARIES - The library needed to use linphonecxx
 if(NOT TARGET ${QTKEYCHAIN_TARGET_NAME})
-    set(EXPORT_PATH ${QTKEYCHAIN_OUTPUT_DIR})
+    set(EXPORT_PATH ${LINPHONE_OUTPUT_DIR})
     include(GNUInstallDirs)
     include(${EXPORT_PATH}/${CMAKE_INSTALL_LIBDIR}/cmake/${QTKEYCHAIN_TARGET_NAME}/${QTKEYCHAIN_TARGET_NAME}Config.cmake)
 endif()
 
-set(_QtKeychain_REQUIRED_VARS QtKeychain_TARGET)
-set(_QtKeychain_CACHE_VARS ${_QtKeychain_REQUIRED_VARS})
+# set(_QtKeychain_REQUIRED_VARS QtKeychain_TARGET)
+# set(_QtKeychain_CACHE_VARS ${_QtKeychain_REQUIRED_VARS})
 
 if(TARGET ${QTKEYCHAIN_TARGET_NAME})
 	set(QtKeychain_TARGET ${QTKEYCHAIN_TARGET_NAME})
 	set(QtKeychain_USE_BUILD_INTERFACE TRUE)
 endif()
 
-include(FindPackageHandleStandardArgs)
-find_package_handle_standard_args(QtKeychain
-	REQUIRED_VARS ${_QtKeychain_REQUIRED_VARS}
-	HANDLE_COMPONENTS
-)
-mark_as_advanced(${_QtKeychain_CACHE_VARS})
-
+#include(FindPackageHandleStandardArgs)
+#find_package_handle_standard_args(QtKeychain
+#	REQUIRED_VARS ${_QtKeychain_REQUIRED_VARS}
+#	HANDLE_COMPONENTS
+#)
+#mark_as_advanced(${_QtKeychain_CACHE_VARS})
