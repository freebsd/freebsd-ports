--- cmake/modules/DefineInstallationPaths.cmake.orig	2018-06-16 07:54:25 UTC
+++ cmake/modules/DefineInstallationPaths.cmake
@@ -114,7 +114,7 @@ ENDIF(EXISTS "/usr/lib64" )
     CACHE PATH "The ${APPLICATION_NAME} sysconfig install dir (default prefix/etc)"
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_PREFIX}/man"
     CACHE PATH "The ${APPLICATION_NAME} man install dir (default prefix/man)"
   )
   SET(INFO_INSTALL_DIR
