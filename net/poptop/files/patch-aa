--- defaults.h.orig	Thu Mar  7 19:09:42 2002
+++ defaults.h	Sun Sep  8 10:19:58 2002
@@ -40,10 +40,14 @@
 #endif
 
 #define PPP_SPEED_DEFAULT		"115200"
+#ifdef __FreeBSD__
+#define PPTPD_CONFIG_FILE_DEFAULT	ETCDIR "/pptpd.conf"
+#else
 #if EMBED
 #define PPTPD_CONFIG_FILE_DEFAULT	"/etc/config/pptpd.conf"
 #else
 #define PPTPD_CONFIG_FILE_DEFAULT	"/etc/pptpd.conf"
+#endif
 #endif
 #define PIDFILE_DEFAULT			"/var/run/pptpd.pid"
 
