--- defaults.h.orig	Wed Apr 28 11:36:07 2004
+++ defaults.h	Thu Oct 20 22:33:48 2005
@@ -45,7 +45,7 @@
 #if EMBED
 #define PPTPD_CONFIG_FILE_DEFAULT	"/etc/config/pptpd.conf"
 #else
-#define PPTPD_CONFIG_FILE_DEFAULT	"/etc/pptpd.conf"
+#define PPTPD_CONFIG_FILE_DEFAULT	"/usr/local/etc/pptpd.conf"
 #endif
 #define PIDFILE_DEFAULT			"/var/run/pptpd.pid"
 
