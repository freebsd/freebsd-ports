--- defines.h.orig	Fri Mar 22 12:30:45 2002
+++ defines.h	Fri Mar 22 12:31:58 2002
@@ -27,7 +27,7 @@
 /***** Change this, or use -c on the command line to specify it *****/
 
 #ifndef SERVER_ROOT
-#define SERVER_ROOT "/etc/boa"
+#define SERVER_ROOT "%%PREFIX%%/etc"
 #endif
 
 /***** Change this via the CGIPath configuration value in boa.conf *****/
