--- xinetd/xconfig.h.orig	Sun Sep 15 19:23:41 2002
+++ xinetd/xconfig.h	Sun Sep 15 19:23:55 2002
@@ -29,7 +29,7 @@
 #endif
 
 
-#define DEFAULT_CONFIG_FILE			"/etc/xinetd.conf"
+#define DEFAULT_CONFIG_FILE			"%%PREFIX%%/etc/xinetd.conf"
 
 /*
  * This is the facility used by xinetd to log syslog messages
