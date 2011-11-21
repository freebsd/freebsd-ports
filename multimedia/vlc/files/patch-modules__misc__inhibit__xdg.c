--- ./modules/misc/inhibit/xdg.c.orig	2011-11-13 19:05:10.000000000 -0500
+++ ./modules/misc/inhibit/xdg.c	2011-11-13 19:06:20.000000000 -0500
@@ -28,6 +28,7 @@
 #include <assert.h>
 #include <spawn.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 static int Open (vlc_object_t *);
 static void Close (vlc_object_t *);
