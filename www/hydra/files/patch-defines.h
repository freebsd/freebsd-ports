--- src/defines.h.orig	Wed Apr  2 22:01:06 2003
+++ src/defines.h	Wed Apr  2 22:02:48 2003
@@ -27,7 +27,7 @@
 /***** Change this, or use -c on the command line to specify it *****/
 
 #ifndef SERVER_ROOT
-#define SERVER_ROOT "/etc/hydra"
+#define SERVER_ROOT "%%PREFIX%%/etc/hydra"
 #endif
 
 /***** Change this via the CGIPath configuration value in hydra.conf *****/
