--- cmake/SmithConfigHeader.cmake.orig	2026-09-30 18:18:35 UTC
+++ cmake/SmithConfigHeader.cmake
@@ -87,5 +87,5 @@ install(
     ${SMITH_INSTALL_CMAKE_MODULE_DIR}
 )
 
-# Install BLT files that recreate BLT targets in downstream projects
-blt_install_tpl_setups(DESTINATION ${SMITH_INSTALL_CMAKE_MODULE_DIR})
+# BLT files are installed by axom (same BLT version); skip to avoid conflicts
+# blt_install_tpl_setups(DESTINATION ${SMITH_INSTALL_CMAKE_MODULE_DIR})
