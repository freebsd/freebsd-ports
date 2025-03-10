--- cmake/par2-turbo.cmake.orig	2024-12-05 05:22:43 UTC
+++ cmake/par2-turbo.cmake
@@ -27,12 +27,6 @@ endif()
 ExternalProject_add(
 	par2-turbo
 	PREFIX			par2-turbo
-	GIT_REPOSITORY	https://github.com/nzbgetcom/par2cmdline-turbo.git
-	GIT_TAG			v1.1.1-nzbget-20241128
-	TLS_VERIFY		TRUE
-	GIT_SHALLOW		TRUE
-	GIT_PROGRESS	TRUE
-	DOWNLOAD_EXTRACT_TIMESTAMP	TRUE
 	CMAKE_ARGS		${CMAKE_ARGS}
 	INSTALL_COMMAND	""
 )
