
$FreeBSD$

--- ztcfg/ztcfg.h	2004/04/30 01:01:39	1.1
+++ ztcfg/ztcfg.h	2004/04/30 01:01:48
@@ -23,6 +23,6 @@
 #ifndef _ZTCFG_H
 #define _ZTCFG_H
 
-#define CONFIG_FILENAME "/etc/zaptel.conf"
+#define CONFIG_FILENAME PREFIX "/etc/zaptel.conf"
 #define MASTER_DEVICE   "/dev/zap/ctl"
 #endif
