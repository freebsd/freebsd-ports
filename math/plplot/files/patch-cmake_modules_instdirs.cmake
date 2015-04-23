--- cmake/modules/instdirs.cmake.orig	2015-04-12 10:08:04 UTC
+++ cmake/modules/instdirs.cmake
@@ -61,13 +61,13 @@ CACHE PATH "install location for C heade
 
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
 
@@ -75,7 +75,7 @@ CACHE PATH "install location for man doc
 # cached values above.
 
 # Data.
-set(DATA_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}${PLPLOT_VERSION})
+set(DATA_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE})
 
 # Libraries.
 set(LIB_DIR ${CMAKE_INSTALL_LIBDIR})
@@ -90,7 +90,7 @@ set(BIN_DIR ${CMAKE_INSTALL_BINDIR})
 set(SHLIB_DIR ${CMAKE_INSTALL_LIBDIR})
 
 # Tcl files.
-set(TCL_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}${PLPLOT_VERSION}/tcl)
+set(TCL_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}/tcl)
 
 # Ada source files (*.adb, *.ads) (following recommendations in
 # http://www.ada-france.org/debian/debian-ada-policy.html
@@ -101,7 +101,7 @@ set(ADA_INCLUDE_DIR ${CMAKE_INSTALL_DATA
 set(ADA_LIB_DIR ${CMAKE_INSTALL_LIBDIR}/ada/adalib/plplotada)
 
 # Drivers.
-set(DRV_DIR ${CMAKE_INSTALL_LIBDIR}/${PACKAGE}${PLPLOT_VERSION}/drivers)
+set(DRV_DIR ${CMAKE_INSTALL_LIBDIR}/${PACKAGE}/drivers)
 
 # Documentation.
 set(DOC_DIR ${CMAKE_INSTALL_DATADIR}/doc/${PACKAGE})
