--- third-party/cmake/GNUInstallDirs.cmake.orig	2024-03-20 11:52:57 UTC
+++ third-party/cmake/GNUInstallDirs.cmake
@@ -172,7 +172,7 @@ if(CMAKE_SYSTEM_NAME MATCHES "(DragonFly|FreeBSD|OpenB
     set(CMAKE_INSTALL_INFODIR "info")
   endif()
 
-  if(NOT CMAKE_INSTALL_MANDDIR)
+  if(NOT CMAKE_INSTALL_MANDIR)
     set(CMAKE_INSTALL_MANDIR "" CACHE PATH "man documentation (man)")
     set(CMAKE_INSTALL_MANDIR "man")
   endif()
@@ -182,7 +182,7 @@ else()
     set(CMAKE_INSTALL_INFODIR "${CMAKE_INSTALL_DATAROOTDIR}/info")
   endif()
 
-  if(NOT CMAKE_INSTALL_MANDDIR)
+  if(NOT CMAKE_INSTALL_MANDIR)
     set(CMAKE_INSTALL_MANDIR "" CACHE PATH "man documentation (DATAROOTDIR/man)")
     set(CMAKE_INSTALL_MANDIR "${CMAKE_INSTALL_DATAROOTDIR}/man")
   endif()
