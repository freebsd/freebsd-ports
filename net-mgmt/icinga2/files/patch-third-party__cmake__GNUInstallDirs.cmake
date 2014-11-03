--- third-party/cmake/GNUInstallDirs.cmake.orig	2014-10-03 15:04:47.712808574 +0200
+++ third-party/cmake/GNUInstallDirs.cmake	2014-10-03 15:05:17.916805737 +0200
@@ -166,7 +166,7 @@
   set(CMAKE_INSTALL_DATADIR "${CMAKE_INSTALL_DATAROOTDIR}")
 endif()
 
-if(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
+if(CMAKE_SYSTEM_NAME MATCHES "^(DragonFly|FreeBSD|OpenBSD)$")
   if(NOT CMAKE_INSTALL_INFODIR)
     set(CMAKE_INSTALL_INFODIR "" CACHE PATH "info documentation (info)")
     set(CMAKE_INSTALL_INFODIR "info")
