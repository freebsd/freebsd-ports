--- ./cmake/modules/instdirs.cmake.orig	2009-09-06 21:04:43.000000000 +0200
+++ ./cmake/modules/instdirs.cmake	2009-12-26 22:13:15.000000000 +0100
@@ -61,13 +61,13 @@
 
 set(
 CMAKE_INSTALL_INFODIR
-${CMAKE_INSTALL_DATADIR}/info
+${CMAKE_INSTALL_PREFIX}/info
 CACHE PATH "install location for info documentation"
 )
 
 set(
 CMAKE_INSTALL_MANDIR
-${CMAKE_INSTALL_DATADIR}/man
+${CMAKE_INSTALL_PREFIX}/man
 CACHE PATH "install location for man documentation"
 )
 
@@ -75,7 +75,7 @@
 # cached values above.
 
 # Data.
-set(DATA_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}${VERSION})
+set(DATA_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE})
 
 # Libraries.
 set(LIB_DIR ${CMAKE_INSTALL_LIBDIR})
@@ -90,7 +90,7 @@
 set(SHLIB_DIR ${CMAKE_INSTALL_LIBDIR})
 
 # Tcl files.
-set(TCL_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}${VERSION}/tcl)
+set(TCL_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}/tcl)
 
 # Ada source files (*.adb, *.ads) (following recommendations in
 # http://www.ada-france.org/debian/debian-ada-policy.html
@@ -101,7 +101,7 @@
 set(ADA_LIB_DIR ${CMAKE_INSTALL_LIBDIR}/ada/adalib/plplotada${LIB_TAG})
 
 # Drivers.
-set(DRV_DIR ${CMAKE_INSTALL_LIBDIR}/${PACKAGE}${VERSION}/drivers${LIB_TAG})
+set(DRV_DIR ${CMAKE_INSTALL_LIBDIR}/${PACKAGE}/drivers${LIB_TAG})
 
 # Documentation.
 set(DOC_DIR ${CMAKE_INSTALL_DATADIR}/doc/${PACKAGE})
