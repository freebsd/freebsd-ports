--- xinetd/xconfig.h.orig	2003-02-19 17:29:28 UTC
+++ xinetd/xconfig.h
@@ -29,7 +29,7 @@
 #endif
 
 
-#define DEFAULT_CONFIG_FILE			"/etc/xinetd.conf"
+#define DEFAULT_CONFIG_FILE			"%%PREFIX%%/etc/xinetd.conf"
 
 /*
  * This is the facility used by xinetd to log syslog messages
