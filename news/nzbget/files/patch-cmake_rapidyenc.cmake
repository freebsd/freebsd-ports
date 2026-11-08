--- cmake/rapidyenc.cmake.orig	2026-08-27 09:51:07 UTC
+++ cmake/rapidyenc.cmake
@@ -55,12 +55,6 @@ ExternalProject_add(
 ExternalProject_add(
 	rapidyenc
 	PREFIX			rapidyenc
-	GIT_REPOSITORY	https://github.com/nzbgetcom/rapidyenc.git
-	GIT_TAG			v1.1.1-20260821
-	TLS_VERIFY		TRUE
-	GIT_SHALLOW		TRUE
-	GIT_PROGRESS	TRUE
-	DOWNLOAD_EXTRACT_TIMESTAMP	TRUE
 	BUILD_BYPRODUCTS ${RAPIDYENC_LIBS}
 	CMAKE_ARGS		 ${CMAKE_ARGS}
 	INSTALL_COMMAND	""
