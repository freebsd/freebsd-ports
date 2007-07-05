--- ./cmakemodules/FindKdeLibs.cmake.orig	Fri Mar  9 03:04:51 2007
+++ ./cmakemodules/FindKdeLibs.cmake	Tue Jun 12 11:11:19 2007
@@ -139,7 +139,7 @@
 ## the following are directories where stuff will be installed to
 SET(BIN_INSTALL_DIR          "${EXEC_INSTALL_PREFIX}/bin"                  CACHE PATH "The kde bin install dir (default prefix/bin)" FORCE)
 SET(SBIN_INSTALL_DIR         "${EXEC_INSTALL_PREFIX}/sbin"                 CACHE PATH "The kde sbin install dir (default prefix/sbin)" FORCE)
-SET(LIB_INSTALL_DIR          "${EXEC_INSTALL_PREFIX}/lib${LIB_SUFFIX}"     CACHE PATH "The subdirectory relative to the install prefix where libraries will be installed (default is /lib${LIB_SUFFIX})" FORCE)
+SET(LIB_INSTALL_DIR          "${EXEC_INSTALL_PREFIX}/lib"     CACHE PATH "The subdirectory relative to the install prefix where libraries will be installed (default is /lib${LIB_SUFFIX})" FORCE)
 SET(LIBEXEC_INSTALL_DIR      "${LIB_INSTALL_DIR}/kde3/libexec"             CACHE PATH "The subdirectory relative to the install prefix where libraries will be installed (default is /lib/kde3/libexec)" FORCE)
 SET(PLUGIN_INSTALL_DIR       "${LIB_INSTALL_DIR}/kde3"                     CACHE PATH "The subdirectory relative to the install prefix where plugins will be installed (default is ${LIB_INSTALL_DIR}/kde3)" FORCE)
 SET(INCLUDE_INSTALL_DIR      "${CMAKE_INSTALL_PREFIX}/include"             CACHE PATH "The subdirectory to the header prefix" FORCE)
