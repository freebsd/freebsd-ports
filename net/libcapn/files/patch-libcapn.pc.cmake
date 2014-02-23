--- ./libcapn.pc.cmake.orig	2013-04-27 14:08:27.000000000 +0800
+++ ./libcapn.pc.cmake	2014-02-21 08:53:31.000000000 +0800
@@ -3,4 +3,4 @@
 Version: ${APN_VERSION}
 Libs: -L${CMAKE_INSTALL_PREFIX}/${APN_INSTALL_PATH_LIB} -l${APN_LIB_NAME}
 Libs.private: -lopenssl
-Cflags: -I${CMAKE_INSTALL_PREFIX}/${APN_INSTALL_PATH_HEADERS}
+Cflags: -I${CMAKE_INSTALL_PREFIX}
