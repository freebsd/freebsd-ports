--- ./src/tickr/tickr.h.orig	2013-06-16 15:01:04.000000000 +0200
+++ ./src/tickr/tickr.h	2013-06-16 15:01:29.000000000 +0200
@@ -173,8 +173,8 @@
 # define STDERR_FILENAME2	"stderr2.txt"
 #endif
 #ifndef G_OS_WIN32
-# define INSTALL_PATH		"/usr/share/" APP_CMD
-# define IMAGES_PATH		INSTALL_PATH "/pixmaps"
+# define INSTALL_PATH		"%%PREFIX%%/share/"
+# define IMAGES_PATH		INSTALL_PATH "/pixmaps/" APP_CMD
 #else
 # define IMAGES_PATH		APP_NAME	/* Actually not a path but a dir name */
 #endif
