--- cmake/admCheckX265.cmake.orig	2016-01-29 08:47:25 UTC
+++ cmake/admCheckX265.cmake
@@ -19,9 +19,6 @@ MACRO(checkX265)
 					MESSAGE("WARNING: x265 core version is too old.  At least version 9 is required.")
 					SET(X265_FOUND 0)
 				ELSE (x265_version LESS 9)
-                                        IF(NOT WIN32)
-                                                SET(DL dl)
-                                        ENDIF(NOT WIN32)
 					FIND_HEADER_AND_LIB(X265 x265.h x265 x265_encoder_open_${x265_version} ${DL})
 				ENDIF (x265_version LESS 9)
 			ELSE (_X265_FOUND AND _X265_CONFIG_FOUND)
