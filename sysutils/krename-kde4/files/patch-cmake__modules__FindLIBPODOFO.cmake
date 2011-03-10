--- ./cmake/modules/FindLIBPODOFO.cmake.orig	2011-02-22 01:00:30.000000000 +0300
+++ ./cmake/modules/FindLIBPODOFO.cmake	2011-03-10 13:33:50.566470837 +0300
@@ -23,7 +23,7 @@
 ENDIF(LIBPODOFO_H)
 
 FIND_LIBRARY(LIBPODOFO_LIB
-	NAMES libpodofo-doc podofo-doc
+	NAMES libpodofo podofo libpodofo-doc podofo-doc
 	PATHS "${LIBPODOFO_DIR}/lib" "${LIBPODOFO_DIR}/src" "${LIBPODOFO_DIR}")
 IF(LIBPODOFO_LIB)
     MESSAGE("podofo lib: ${LIBPODOFO_LIB}")
