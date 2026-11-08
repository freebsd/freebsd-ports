--- cmake/par2-turbo.cmake.orig	2026-08-27 09:51:07 UTC
+++ cmake/par2-turbo.cmake
@@ -56,11 +56,6 @@ ExternalProject_add(
 ExternalProject_add(
 	par2-turbo
 	PREFIX			par2-turbo
-	GIT_REPOSITORY	https://github.com/nzbgetcom/par2cmdline-turbo.git
-	GIT_TAG			v1.4.0-20260803
-	TLS_VERIFY		TRUE
-	GIT_SHALLOW		TRUE
-	GIT_PROGRESS	TRUE
 	DOWNLOAD_EXTRACT_TIMESTAMP	TRUE
 	BUILD_BYPRODUCTS ${PAR2_LIBS}
 	CMAKE_ARGS		 ${CMAKE_ARGS}
