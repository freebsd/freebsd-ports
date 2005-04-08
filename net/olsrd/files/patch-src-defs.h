--- src/defs.h.orig	Fri Apr  1 07:14:22 2005
+++ src/defs.h	Sat Apr  9 00:08:01 2005
@@ -64,8 +64,10 @@
 #define SOFTWARE_VERSION "olsr.org - " VERSION
 #define OLSRD_VERSION_DATE "       *** " SOFTWARE_VERSION " (" __DATE__ ") ***\n"
 
+#ifndef OLSRD_GLOBAL_CONF_FILE
 #define OLSRD_CONF_FILE_NAME "olsrd.conf"
 #define OLSRD_GLOBAL_CONF_FILE "/etc/" OLSRD_CONF_FILE_NAME
+#endif
 
 #define	HOPCNT_MAX		32	/* maximum hops number */
 #define	MAXMESSAGESIZE		1500	/* max broadcast size */
