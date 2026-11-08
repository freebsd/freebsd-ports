--- gretl/cmake/GretlConfigHeader.cmake.orig	2026-08-13 02:48:06 UTC
+++ gretl/cmake/GretlConfigHeader.cmake
@@ -106,5 +106,5 @@ install(
     ${GRETL_INSTALL_CMAKE_MODULE_DIR}
 )
 
-# Install BLT files that recreate BLT targets in downstream projects
-blt_install_tpl_setups(DESTINATION ${GRETL_INSTALL_CMAKE_MODULE_DIR})
+# BLT files are installed by axom (same BLT version); skip to avoid conflicts
+# blt_install_tpl_setups(DESTINATION ${GRETL_INSTALL_CMAKE_MODULE_DIR})
