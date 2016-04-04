--- logd/ha_logd.c.orig	2014-10-16 17:24:17 UTC
+++ logd/ha_logd.c
@@ -59,8 +59,8 @@
   
 
 
-#define DEFAULT_CFG_FILE	HA_SYSCONFDIR "/logd.cf"
-#define	LOGD_PIDFILE		HA_VARRUNDIR "/logd.pid"
+#define DEFAULT_CFG_FILE	HA_SYSCONFDIR "/ha_logd.cf"
+#define	LOGD_PIDFILE		HA_VARRUNDIR "/ha_logd.pid"
 
 #define	FD_STDIN	0
 #define	FD_STDOUT	1
