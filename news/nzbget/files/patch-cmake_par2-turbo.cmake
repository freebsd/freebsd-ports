--- cmake/par2-turbo.cmake.orig	2025-07-01 18:05:03 UTC
+++ cmake/par2-turbo.cmake
@@ -51,12 +51,6 @@ endif()
 ExternalProject_add(
 	par2-turbo
 	PREFIX			par2-turbo
-	GIT_REPOSITORY	https://github.com/nzbgetcom/par2cmdline-turbo.git
-	GIT_TAG			v1.3.0
-	TLS_VERIFY		TRUE
-	GIT_SHALLOW		TRUE
-	GIT_PROGRESS	TRUE
-	DOWNLOAD_EXTRACT_TIMESTAMP	TRUE
 	BUILD_BYPRODUCTS ${PAR2_LIBS}
 	CMAKE_ARGS		 ${CMAKE_ARGS}
 	INSTALL_COMMAND	""
