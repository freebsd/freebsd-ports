--- cmake/modules/FindLIBPODOFO.cmake.orig	2022-01-23 16:16:42 UTC
+++ cmake/modules/FindLIBPODOFO.cmake
@@ -13,7 +13,7 @@ find_path(LIBPODOFO_INCLUDE_DIR
 endif(WIN32)
 
 find_path(LIBPODOFO_INCLUDE_DIR
-	NAMES podofo/podofo.h
+	NAMES podofo09/podofo.h
 	PATHS
 	"${LIBPODOFO_DIR}/include"
 	"${LIBPODOFO_DIR}/src"
@@ -23,7 +23,7 @@ find_library(LIBPODOFO_LIBRARY
 set(LIBPODOFO_FIND_QUIETLY ON)
 
 find_library(LIBPODOFO_LIBRARY
-	NAMES libpodofo podofo
+	NAMES libpodofo09 podofo09
 	PATHS
 	"${LIBPODOFO_DIR}/lib"
 	"${LIBPODOFO_DIR}/src"
@@ -32,7 +32,7 @@ if(LIBPODOFO_INCLUDE_DIR AND LIBPODOFO_LIBRARY)
 
 if(LIBPODOFO_INCLUDE_DIR AND LIBPODOFO_LIBRARY)
 	if(NOT LIBPODOFO_CONFIG_H)
-		set(LIBPODOFO_CONFIG_H "${LIBPODOFO_INCLUDE_DIR}/podofo/base/podofo_config.h" CACHE FILEPATH "Alternative place of podofo_config.h")
+		set(LIBPODOFO_CONFIG_H "${LIBPODOFO_INCLUDE_DIR}/podofo09/base/podofo_config.h" CACHE FILEPATH "Alternative place of podofo_config.h")
 	endif()
 
 	file(STRINGS "${LIBPODOFO_CONFIG_H}" PODOFO_MAJOR_VER_LINE REGEX "^#define[ \t]+PODOFO_VERSION_MAJOR[ \t]+[0-9]+$")
@@ -69,14 +69,14 @@ if(NOT LIBPODOFO_FIND_QUIETLY)
 
 if(NOT LIBPODOFO_FIND_QUIETLY)
 	if(LIBPODOFO_INCLUDE_DIR)
-		message("podofo/podofo.h: ${LIBPODOFO_INCLUDE_DIR}")
+		message("podofo09/podofo.h: ${LIBPODOFO_INCLUDE_DIR}")
 	else(LIBPODOFO_INCLUDE_DIR)
-		message("podofo/podofo.h: not found")
+		message("podofo09/podofo.h: not found")
 	endif(LIBPODOFO_INCLUDE_DIR)
 	if(LIBPODOFO_LIBRARY)
-		message("podofo lib: ${LIBPODOFO_LIBRARY}")
+		message("podofo09 lib: ${LIBPODOFO_LIBRARY}")
 	else(LIBPODOFO_LIBRARY)
-		message("podofo lib: not found")
+		message("podofo09 lib: not found")
 	endif(LIBPODOFO_LIBRARY)
 	message("PoDoFo cflags: ${useshared}")
 endif(NOT LIBPODOFO_FIND_QUIETLY)
