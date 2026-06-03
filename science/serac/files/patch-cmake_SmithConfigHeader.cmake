--- cmake/SmithConfigHeader.cmake.orig	2026-03-31 21:26:15.628537000 -0700
+++ cmake/SmithConfigHeader.cmake	2026-03-31 21:26:45.170889000 -0700
@@ -117,5 +117,5 @@
     ${SMITH_INSTALL_CMAKE_MODULE_DIR}
 )
 
-# Install BLT files that recreate BLT targets in downstream projects
-blt_install_tpl_setups(DESTINATION ${SMITH_INSTALL_CMAKE_MODULE_DIR})
+# BLT files are installed by axom (same BLT version); skip to avoid conflicts
+# blt_install_tpl_setups(DESTINATION ${SMITH_INSTALL_CMAKE_MODULE_DIR})
