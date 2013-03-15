--- ./src/tickr/tickr.h.orig	2013-03-15 14:10:30.000000000 +0100
+++ ./src/tickr/tickr.h	2013-03-15 14:11:17.000000000 +0100
@@ -178,8 +178,8 @@
 # define STDERR_FILENAME2	"stderr2.txt"
 #endif
 #ifndef G_OS_WIN32
-# define INSTALL_PATH		"/usr/share/"APP_CMD
-# define IMAGES_PATH		INSTALL_PATH"/pixmaps"
+# define INSTALL_PATH		"%%PREFIX%%/share/"
+# define IMAGES_PATH		INSTALL_PATH"/pixmaps/"APP_CMD
 #else
 # define IMAGES_PATH		APP_NAME	/* actually not a path but a dir name */
 #endif
