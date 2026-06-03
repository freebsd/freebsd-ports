--- gretl/cmake/GretlConfigHeader.cmake.orig	2026-03-31 22:10:13.885368000 -0700
+++ gretl/cmake/GretlConfigHeader.cmake	2026-03-31 22:11:01.296363000 -0700
@@ -106,5 +106,5 @@
     ${GRETL_INSTALL_CMAKE_MODULE_DIR}
 )
 
-# Install BLT files that recreate BLT targets in downstream projects
-blt_install_tpl_setups(DESTINATION ${GRETL_INSTALL_CMAKE_MODULE_DIR})
+# BLT files are installed by axom (same BLT version); skip to avoid conflicts
+# blt_install_tpl_setups(DESTINATION ${GRETL_INSTALL_CMAKE_MODULE_DIR})
