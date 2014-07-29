--- src/iplog.h.orig	Mon Jul  3 16:49:23 2000
+++ src/iplog.h	Tue Jul  4 08:18:35 2000
@@ -28,7 +28,7 @@
 ** Path of the iplog configuration file.
 */
 
-#define CONFFILE	"/etc/iplog.conf"
+#define CONFFILE	"%%PREFIX%%/etc/iplog.conf"
 
 /*
 ** Making these smaller will probably do bad things.
